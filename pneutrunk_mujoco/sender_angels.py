import os
import numpy as np
import joblib
import mujoco
import mujoco.viewer
import time
from keras.models import load_model

# Paste your path
base_path = " your file path "

# Load all trained models and scalers
models = {}
scalers_X = {}
scalers_y = {}

for i in range(1, 7):
    model_path = os.path.join(base_path, f'nn_module_{i}v4.0.h5')
    scaler_X_path = os.path.join(base_path, f'scaler_X_{i}.pkl')
    scaler_y_path = os.path.join(base_path, f'scaler_y_{i}.pkl')

    models[i] = load_model(model_path)
    scalers_X[i] = joblib.load(scaler_X_path)
    scalers_y[i] = joblib.load(scaler_y_path)

print("All models and scalers loaded.")

# Load MuJoCo model
xml_path = ' your file path '
mj_model = mujoco.MjModel.from_xml_path(xml_path)
data = mujoco.MjData(mj_model)

# Example pressure input for each module
test_inputs = {
    i: np.array([[1.2, 1.8, 0.6]]) for i in range(1, 7)
}

# Predict angles from input pressure
predicted_angles = {}
for i in range(1, 7):
    X_scaled = scalers_X[i].transform(test_inputs[i])
    y_scaled = models[i].predict(X_scaled)
    angles = scalers_y[i].inverse_transform(y_scaled)
    predicted_angles[i] = angles[0]

# Print predicted angles (in degrees)
for i in range(1, 7):
    print(f"Module {i}: Pressure = {test_inputs[i][0]}, Angles (deg) = {predicted_angles[i]}")

# Apply angles to simulation (converted to radians)
for i in range(1, 7):
    angles_rad = np.deg2rad(predicted_angles[i])
    print(f"Module {i}: Angles (rad) = {angles_rad}")
    data.ctrl[2 * (i - 1)] = angles_rad[0]
    data.ctrl[2 * (i - 1) + 1] = angles_rad[1]

# Launch MuJoCo viewer
print("Launching simulation...")
viewer = mujoco.viewer.launch_passive(mj_model, data)
viewer.cam.lookat[:] = [0.0, 0.0, 1.3]
viewer.cam.distance = 2
viewer.cam.azimuth = 1.8
viewer.cam.elevation = -2
print("Viewer running. Press ESC to close.")

while viewer.is_running():
    mujoco.mj_step(mj_model, data)
    viewer.sync()
    time.sleep(0.01)