# ESP32_w_ArduinoIDE
 Basic scripts to run ESP32 with Arduino IDE

 I've purchased a simple development board from AliExpress to step into the magical world of ESP32. [The development board](http://www.chinalctech.com/cpzx/1/515.html) includes a relay, an LED, and a button in addition to the ESP32-WROOM-32E module.
 This repository includes the scripts that I wrote to learn ESP32 by using ArduinoIDE.

## How to install the Arduino-ESP32 support?
Follow the steps given in the link below and select ESP32 Dev Module as the board in Arduino IDE:

https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html#installing-using-arduino-ide

 ## How to connect the ESP32 module to a host computer and upload a script?
 To connect the ESP32 module to a computer, if it doesn't have any built-in USB interface, an external USB-to-serial adapter is required. CH-340 and PL-2303 are the most common IC's that can interface between the USB port of the host computer and the devices with serial output.

 Before uploading a script to ESP32, GPIO0 must be LOW to enter flashing mode. So, before flashing a script to the ESP32 development board, connect it to the computer while pressing the button connected to GPIO0.
 
 ## Pin numbers of peripherals
 * **Button:** GPIO0	
 * **Relay:** GPIO16	
 * **LED:** GPIO23
   
 ## Some useful links
 * **Development board information page:** http://www.chinalctech.com/cpzx/1/515.html
 * **Development board in AliExpress:** https://www.aliexpress.com/item/1005006258003606.html
 * **USB-to-serial adapter in AliExpress:** https://www.aliexpress.com/item/32529737466.html
 * **ESP32-WROOM-32E datasheet:** https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf
 

