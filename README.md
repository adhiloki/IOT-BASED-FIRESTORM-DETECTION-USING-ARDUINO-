# IOT-BASED-FIRESTORM-DETECTION-USING-ARDUINO-
IoT-based firestorm detection is a very useful concept because in a forest some of the remote areas we can’t communicate or monitor those areas, it will process than it will send the data to operators by using cloud storage. Fire outbreak has been a common issue in forests and large buildings. In this research we will detect forest fires by using flame sensor and image processing. We can read RGB values when fire has been occured

**ARDUINO UNO BOARD**

 ![image](https://user-images.githubusercontent.com/78494843/185980172-aba5d69a-7e74-4dee-8a5c-8afd1cc3234f.png)

The major components of the Arduino UNO board are following

USB connector: this is a printer USB port used to load a program from the Arduino IDE onto the Arduino board.
The board can also be powered through this port.

Power port: The Arduino UNO board operates at a voltage of 5 volts, max 20 volts.

Microcontroller: it is a black rectangular chip with 28 pins. The microcontroller used on the UNO board isAtmega328P by Atmel

Atmega328P has the following components in it
Flash memory of 32KB. The program loaded from the Arduino IDE is stored here. RAM of 2KB. This is runtime memory
▸ CPU: It controls everything that goes on within the device. It fetches the program instructions from flash memory and runs it with the help of RAM
▸ Electrically Erasable Programmable Read-Only Memory (EEPROM) of 1KB. This is a type of nonvolatile memory, and it keeps the data even after device restart and reset
Atmega328P is pre-programmed with the bootloader. This allows you to directly upload a new Arduino program into the device, without using any external hardware programmer, making the Arduino UNO board easy to use

Analog input pins: The Arduino UNO board has 6 analog input pins, labeled "Analog 0 to 5." These pins can read the signal from an analog sensor such as a temperature sensor and convert it into a digital value for system understanding
These pins just measure voltage and not the current because they have very high internal resistance. Hence, only a small amount of current flows through these pins
 Although these pins are labeled analog and are analog input by default, these pins can also be used for digital input or output

Digital pins: we can find these pins labeled “digital 0 to 13”. These pins can be used as either input or output pins. When used as output, these pins act as power supply sources for the components connected to it & when used as input pins, they read the signals.

Reset switch: when this switch is clicked, it sends a logical pulse to the reset pin of the microcontroller, and now runs the program again from  the start
This can be very useful if your code doesn't repeat, and you want to test it multiple time

Crystal oscillator: this is a quart crystal oscillator that ticks 16 million times a second. On each tick, the microcontroller performs one operation.
USB interface chip:  it converts signals in the USB level to a level  that an Arduino UNO board understandings

TX RX indicator: TX stands for transmitting, and RX for receive. These are indicated LEDs that blink the UNO board is transmitting or receiving data

**FLAME SENSOR**

Flame Sensor can be used to detect fire sources or other light sources within a short range. The working principle behind these sensors is sensitivity to the IR (Infrared) wavelength at 760nm – 1100nm.
![image](https://user-images.githubusercontent.com/78494843/185981265-31ea8e7f-03dd-48bf-bcd9-ef7fa2286ca3.png)

The flame sensor module has the following features:
•	The operating voltage is from 3.3 – 5V.
•	It gives us both analog and digital output.
•	It has a led indicator, which indicates whether the flame is detected or not.
•	The threshold value can be changed by rotating the top of a potentiometer.
•	Flame detection distance, the lighter flame test can be triggered within 0.8m, if the intensity of the flame is high, the detection distance will be increased.
•	The detection angle of the flame sensor module is about 60 degrees.

**WIFI MODULE**

Wi-Fi module also known as serial to Wi-Fi module, which belongs to the transmission layer of IoT. It is capable of hosting an application or offloading all Wi-Fi networking functions from another application processor.
ESP8266-01 Pinout
•	VCC: connect to +3.3V power source. don’t connect it with a 5V source it will get damaged.
•	GND: -ve pin, connect it to the ground of your circuit.
•	CH_PD: chip enables pin – Active HIGH. connect it to a logic value HIGH to allow the module to boot up.
•	RST: Chip Reset pin – Active LOW, when it pulled LOW it Resets the module.
•	GPIO0, GPIO2: General purpose input/output pins.
•	Tx: connect to the Rx of the microcontroller(Arduino) to establish serial communication.
•	Rx: connect to the Tx of the microcontroller(Arduino) to establish serial communication.
![image](https://user-images.githubusercontent.com/78494843/185978588-949c4c00-54fa-4827-9115-77fa9c216d98.png)
![image](https://user-images.githubusercontent.com/78494843/185978836-9cd8e4ac-0da0-49ee-b53f-07771152d74c.png)


  
**CMOS Sensor(color sensor)**

![image](https://user-images.githubusercontent.com/78494843/185979537-c5be0fea-7152-44e9-97b8-eedce5fe58bc.png)
                      
•	A CMOS sensor is an electronic chip that converts photons to electrons for digital processing. CMOS sensors are used to create images in pixel form which captures one by one pixels in digital cameras, digital video cameras and digital CCTV cameras. 
•	The module has an 8×8 photodiode array, 16 of them with Red filter, 16 with blue one, 16 with green one and 16 without a filter (clear), we select what filter to use and read its value, and in the code we combine them depending on the application or project.
•	The light is detected by the photodiodes and the output is a frequency proportional to the current flowing through the photodiodes which is related to the filter used and the object’s color detected.




**WORKING PROCESS**
**Flame Sensor**

![image](https://user-images.githubusercontent.com/78494843/185979338-d529e514-e1a9-4a8f-a611-a00ef66e6405.png)

When we place a flame near flame sensor the Arduino will receive the LOW input and when we remove flame from the flame sensor Arduino will receive the HIGH input from the flame sensor.
 

**Arduino colour detection**

![image](https://user-images.githubusercontent.com/78494843/185980038-e6a28a13-6fde-463b-b221-a71a48b05f1e.png)

 
-The module has (Vcc/GND) pins, they are redundant.
– S0/S1 pins control the output frequency scalling
– S2/S3 pins control which set of photodiodes we gonna measure (Red/Green/Blue/Clear)
– Out is the output signal and LED pin controls the LEDs on the front.

![image](https://user-images.githubusercontent.com/78494843/185979239-304b7814-1022-4e61-87ba-3d447d68f742.png)
 
Output frequency scalling modes
This option permits the module to be used with different measuring techniques, and types of microcontrollers, in the tutorial and codes I kept using it at 100%, you can change it if you want it depends just on the logic level of their pins (HIGH/LOW).

![image](https://user-images.githubusercontent.com/78494843/185979281-55035fbf-900e-4f88-aa33-a77182c186af.png)

 
Photodiode set selection
By also controlling the logic levels of S2/S3 we can select which filter or no filter to use, in the code I go through Red/Green/Blue, if your application require one or two filters only you can do it too.
For the LED pin, if it’s not connected, the LEDs will light up automatically, but if you want to turn them off you can put the LED pin to LOW, (it depends on your application and condition).
For the Out pin, as the signal given by the sensor is a frequency,  we measure the duration as they are related (Duration=1/Frequency), so the higher the frequency of a color, the lower is the duration measured, which means that the object detected has that color (check the tutorial).


**WIFI Module (ESP 01)**

![image](https://user-images.githubusercontent.com/78494843/185979635-98796d6c-b958-4143-b2af-cddbbb3fe109.png)
![image](https://user-images.githubusercontent.com/78494843/185979674-ea4225ad-2f0e-488e-8ad1-3acd37eb4b72.png)

The ESP-01 will be used as a Serial Bridge, what means that we will program it using " AT commands". The first thing is to be sure that our ESP-01 is on the correct Baud Rate communication speed. In our case, 9,600 bauds. Usually, the ESP-01 come programmed from the factory with 115,200 baud and we must change it to 9,600 baud.
ESP-01 is an inexpensive, small-sized Wi-Fi module, which consists of TCP/IP stack along with a built-in microcontroller. So, we can directly program this small chip and can bring Wi-Fi capability in our project. 
In this project, we are using Arduino IDE in order to upload code in ESP-01 and will write code by using the APIs and will send an HTTP request to the server and will write a data in ThingSpeek channel.

**ThingSpeak.com** 
  
The "Centre of our IoT project" will be the ThingSpeak.com. The local unit (UNO/ESP-01) will capture data from sensors and actuator status, send them to the Internet, "writing" on a specific ThingSpeak.com Status Channel. The local unit will also receive data from the internet, "reading" them from specific Thing Speak Actuator Channels.
 Project will capture several data, sending them to the cloud, where everyone can see them thru the internet. To work those data, we will use the service provided by ThingSpeak.com, an open IoT platform that will permit us to collect, analyze and act on those data.
 ![image](https://user-images.githubusercontent.com/78494843/185979080-74419783-8e49-4fd4-84cd-e9eed1857208.png)

****OUTPUT****

![image](https://user-images.githubusercontent.com/78494843/185980524-bb4d1bc4-586a-4ac6-870c-2cf654ab0d6d.png)
![image](https://user-images.githubusercontent.com/78494843/185980549-c18477b3-11f5-43ba-afde-bbc0ad30abac.png)

