# Lights

Led strip that reacts to the volume and pitch of incoming sounds. 

### TODO

* Display aux vol & pitch
* Voice recognition; need mic
* Display room volume and pitch; need mic





Parts: 
k = number of led nodes; k < 7
* KY-038 - Microphone
* (k+1) Arduino Nano - MCU
* (k+1) nRF24L01+ - WiFi transmitter
* (k) WS2812B - LED Strip
* (k) Batteries
* 10mf capacitors
* resistors

### Power 

#### WS2812B

vdd: between 3.5V and 5.3V

inp current: datasheet says between +1 and -1 μA??? Going with ~50mA per LED 

max curr: 5 * 30 * 50mA = 7.5A 

#### nRF24L01+ 

vdd max 3.6V

10nF capacitor between vdd and gnd as close to vdd as possible

max inp curr: 13.5mA (rx 2mbps) 

#### Arduino Nano

vdd max 5V

current draw ~15mA


#### Power supply

voltage: 5V

max current > 7500 + 13.5 + 15 = 7.5285A


### Audio to lights signal

Microsoft Wave format: http://soundfile.sapp.org/doc/WaveFormat/
Read wav data to bytes: https://stackoverflow.com/questions/13660777/c-reading-the-data-part-of-a-wav-file

Map Bytes stream of raw LPCM to RGB function
each channel is represented by a 2 byte unsigned int
=> LPCM is 4 bytes unsigned int
to 






