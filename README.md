# ESP32 Thermal Imaging Sensor (MLX90640) Project

### Project Overview
The ESP32 Thermal Imaging Sensor project demonstrates how to interface an MLX90640 thermal camera sensor with an ESP32 microcontroller to measure average temperature from its field of view. The MLX90640 sensor uses I2C communication to provide a 24x32 pixel thermal image, which allows for non-contact temperature sensing over a wide area.

### Components Needed
- **ESP32 Microcontroller**: Controls and processes sensor data.
- **MLX90640 Thermal Camera Sensor**: Provides thermal imaging capabilities.
- **Jumper Wires**: Connects the MLX90640 sensor to the ESP32.
- **Breadboard**: Optional, for organizing circuit connections.

### Block Diagram

### Circuit Setup
1. **Connecting the MLX90640 Sensor to ESP32:**
   - **I2C Communication**: Connect the MLX90640 sensor's SDA (data) and SCL (clock) pins to the ESP32's corresponding SDA and SCL pins (often GPIO 21 and GPIO 22 respectively).
   - **Power Supply**: Provide suitable power (3.3V) and ground connections to the MLX90640 sensor.

### Instructions
1. **Setup:**
   - Initialize Serial communication using `Serial.begin(115200)` for debugging purposes.
   - Initialize I2C communication using `Wire.begin()`.

2. **Operation:**
   - **Initializing the Sensor:**
     - Use `mlx.begin(MLX90640_I2CADDR, &Wire)` to initialize the MLX90640 sensor with its I2C address.
     - Set the sensor refresh rate and mode using `mlx.setRefreshRate(MLX90640_RATE_16HZ)`.

   - **Reading Temperature:**
     - Create an array `mlx90640To[768]` to store temperature data.
     - Use `mlx.getFrameData(mlx90640To)` to read temperatures from the sensor.
     - Calculate the average temperature from the sensor data array.

   - **Output:**
     - Print the average temperature to the Serial Monitor using `Serial.print` and `Serial.println`.

3. **Considerations:**
   - **Sensor Calibration:** Understand and calibrate the MLX90640 sensor if precise temperature measurements are required.
   - **Power Supply:** Ensure stable power supply to the sensor for accurate readings.
   - **Temperature Range:** Check the temperature range supported by the MLX90640 sensor.

### Applications
- **Building Automation:** Monitor temperature distribution in rooms.
- **Industrial Processes:** Monitor equipment temperatures remotely.
- **Medical Applications:** Check body temperatures for fever detection.

### Useful Links
🌐 [ProjectsLearner - ESP32 Thermal Imaging Sensor](https://projectslearner.com/learn/esp32-thermal-imaging-sensor)  
📧 [Email](mailto:projectslearner@gmail.com)  
📸 [Instagram](https://www.instagram.com/projectslearner/)  
📘 [Facebook](https://www.facebook.com/projectslearner)  
▶️ [YouTube](https://www.youtube.com/@ProjectsLearner)  
📘 [LinkedIn](https://www.linkedin.com/in/projectslearner)

Created with ❤️ by ProjectsLearner
