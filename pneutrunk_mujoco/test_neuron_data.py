import os
import numpy as np
import joblib
from keras.models import load_model

# Paste your file path
base_path = " your file path "
model_path = os.path.join(base_path, 'nn_module_1v4.0.h5')
scaler_X_path = os.path.join(base_path, 'scaler_X_1.pkl')
scaler_y_path = os.path.join(base_path, 'scaler_y_1.pkl')

# Load model and scalers
model = load_model(model_path)
scaler_X = joblib.load(scaler_X_path)
scaler_y = joblib.load(scaler_y_path)

# Input pressure example
pressure_input = np.array([[0.3, 0.6, 1.2]])

# Scale input
pressure_scaled = scaler_X.transform(pressure_input)

# Predict angles
predicted_scaled = model.predict(pressure_scaled)
predicted_angles = scaler_y.inverse_transform(predicted_scaled)

# Output results
print("Input pressure:", pressure_input)
print("Predicted angles:", predicted_angles[0])