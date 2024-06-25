/*
   Project name: ESP32 Thermal Imaging Sensor (MLX90640)
   Modified Date: 25-06-2024
   Code by: Projectslearner
   Website: https://projectslearner.com/learn/esp32-thermal-imaging-sensor
*/

#include <Wire.h>
#include <Adafruit_MLX90640.h>

// Define the I2C address for the MLX90640 sensor
#define MLX90640_I2CADDR 0x33

// Create a MLX90640 instance
Adafruit_MLX90640 mlx;

void setup() {
  Serial.begin(115200); // Initialize serial communication
  Wire.begin(); // Initialize I2C communication

  // Attempt to initialize the MLX90640 sensor
  if (!mlx.begin(MLX90640_I2CADDR, &Wire)) {
    Serial.println("Failed to find MLX90640 chip");
    while (1);
  }

  // Set refresh rate and mode
  mlx.setRefreshRate(MLX90640_RATE_16HZ); // 16Hz refresh rate

  // Initialize the sensor
  Serial.println("MLX90640 ready!");
}

void loop() {
  // Create an array to store the temperatures (24x32 pixels)
  float mlx90640To[768];

  // Attempt to read temperatures from the sensor
  if (mlx.getFrameData(mlx90640To) != MLX90640_OK) {
    Serial.println("Failed to read MLX90640");
    return;
  }

  // Calculate the average temperature from the sensor data
  float averageTemperature = 0.0;
  for (int i = 0; i < 768; i++) {
    averageTemperature += mlx90640To[i];
  }
  averageTemperature /= 768.0;

  // Print the average temperature to the Serial Monitor
  Serial.print("Average Temperature: ");
  Serial.print(averageTemperature, 2); // Print with 2 decimal places
  Serial.println(" °C");

  delay(1000); // Delay before the next reading
}
