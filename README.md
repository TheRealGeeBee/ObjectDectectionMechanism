# ObstacleDectectionMechanism

This is a basic obstacle detection mechanism using Arduino. I did the project to test my understanding of the concepts I was being taught in the Robotics classes.

**_HOW THE DEVICE WORKS_**

The device can detect obstacles up to a distance of a little above 1 metre (depends on the capacity of the ultrasonic sensor you use though). When it detects an obstacle beyond 400 centimetres, it prints the message _Out of Range!_ and the distance of the obstacle on the LCD screen. When it detects an obstacle between 45 centimetres and 80 centimetres, it prints _Obstacle Detected!_ and the obstacle's distance on the LCD screen. It also turns on the LED and rotates the servo motor for 5 seconds. Any other distance outside these ranges, the device simply prints the obstacle's distance on the LCD screen.

**LIST OF DEVICES USED**

**1. _Arduino Uno_**

**2. _A 16 x 2 LCD Screen_**

**3. _An ultrasonic sensor_**

**4. _A Light Emitting Diode_**

**5. _A potentiometer_**

**6. _A Servo motor_**

_(The Servo motor and the LED are optional. They were included for additional functionality. The Potentiometer is only used to act as an obstacle in the simulation, it is not required in real life applications)_

