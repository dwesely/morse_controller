# morse_controller
USB morse key adapter based on the CH32v003

## Components:

OLED/rotary encoder
Push encoder: enter program mode
Cycle through 4 settings:
* Key1: default space bar, then LMB, RMB, common keys
* Key2: default empty, then space bar, LMB, RMB, common keys
* End: default empty, then E, then common ends
* End Delay: speed in wpm, where delay until end is 7*1.2/[wpm] seconds (empty if End is empty)
Push the encoder button to cycle through options, then push at the end to write the values and reset the device (setting up the key)


## Development for V2:

* Gather the hardware (done)
* Map the pins
* Breadboard the hardware
* Blink
* Display 4 lines of text with space for a cursor
* Turn off display on timeout
* Turn on display on rotary press
* Enter "configuration mode" on rotary press (show cursor)
* Change row on button press (indicated by a cursor)
* Reset on last rotary button press (pulsing D- low in user-code? reboot?) - ignore rotary 
* Cycle through characters on rotary spin (only when in "configuration mode")
* Write values to EEPROM on button press
* Read EEPROM on boot
* Send space on morse press
* Send LMB on morse press
* Send read key on morse press
* Send end character after delay
* Finalize/package the hardware
* Make a case

## Needed pins:
  
 * VDD - VCC
 * VSS - GND
 * PD1 - SWIO
 * PD4 - USB D+
 * PD3 - USB D-
 * PC2 - Display SCL
 * PC1 - Display SDA
 * PC4 - Rotary button
 * PA2 - Rotary A
 * PA1 - Rotary B
 * PD5 - Key 1
 * PD6 - Key 2
 * PD7 - LED
