import os
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import mean_squared_error
from keras.models import Sequential
from keras.layers import Dense
import joblib

# Paste your path
data_path = " your file path"
save_path = " your file path"

# Load dataset
data = pd.read_excel(data_path)
data.columns = data.columns.astype(str)

# Inputs (pressure) and targets (angles)
X = data.iloc[:, :3].values
y = data.iloc[:, 3:5].values

# Split into train and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Scale data
scaler_X = StandardScaler()
scaler_y = StandardScaler()
X_train_scaled = scaler_X.fit_transform(X_train)
X_test_scaled = scaler_X.transform(X_test)
y_train_scaled = scaler_y.fit_transform(y_train)
y_test_scaled = scaler_y.transform(y_test)

# Build neural network
model = Sequential()
model.add(Dense(64, activation='relu', input_shape=(3,)))
model.add(Dense(64, activation='relu'))
model.add(Dense(2))  # 2 outputs for angles
model.compile(optimizer='adam', loss='mse', metrics=['mae'])

# Train the model
model.fit(X_train_scaled, y_train_scaled, epochs=100, batch_size=16, validation_split=0.1, verbose=1)

# Evaluate model
y_pred_scaled = model.predict(X_test_scaled)
y_pred = scaler_y.inverse_transform(y_pred_scaled)
mse = mean_squared_error(y_test, y_pred)
print("Mean Squared Error:", mse)

# Save model and scalers
model.save(os.path.join(save_path, 'nn_module_2v4.0.h5'))
joblib.dump(scaler_X, os.path.join(save_path, 'scaler_X_2.pkl'))
joblib.dump(scaler_y, os.path.join(save_path, 'scaler_y_2.pkl'))
print("Model and scalers saved to:", save_path)