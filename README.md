# ESP32-Sensors-and-Wifi-in-Max

This is an interactive box which control "boids" in Max/MSP via sensors connected to an ESP32.

Parts list:
ESP32
Breadboard
Ambient Light Sensor
Piezoelectric Sensor
DIY Force Resistance Sensor
Lipo Battery
Breadboard
Wires 
Wooden Enclosure 

 On a high level, the computer is running some JavaScript code which is generating "boids" which move around a 2D plane which 
 is visible on the screen in Max. When a sound file is loaded into the buffer in Max, these boids take on specific meaning. 
 Specifically, the X position of each boid represents the position of playback in the loaded buffer, For example, if the boid 
 is all the way to the let, it will play at the beginning of the buffer. If the boid is right in the middle of screen, it 
 will play halfway through the buffer. The Y position of each boid represents the speed of playback. The user has control 
 over the number of boids generated, which can range from 1 to about 200, after which the audio processing gets to be a bit 
 too much to handle (at least on my computer).
 
 The physics of the boids are controlled via the the interactive box I built. There are 3 active sensors: an ambient 
 light sensor, a force resistance sensor, and a piezo sensor which is located under the top of the box. The player can 
 play with sensors individually or simultaneously (as demonstrated in the video). The specific manner in which the sensors 
 affect the boids is left a bit vague on purpose; essentially they have different affects but it is difficult to tell what 
 exactly they are affecting because of the complex physics of the boids. Some of the physics parameters include a 
 separation force (how much the boids want to repel from each other), a cohesion force (how attracted the boids are 
 to each other), a speed limit (the maximum speed of the boids), and a point of attraction (where the boids are 
 attracted to on an XY plane).
