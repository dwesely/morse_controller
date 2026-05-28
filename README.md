# morse_controller
USB morse key adapter based on the CH32v003

Plug your morse key (straight key or paddle), and the device acts as a keyboard and/or a mouse to send keypresses or mouse presses to a PC. This allows a real morse key to be used as a controller for a variety of morse code games/programs.

This is an updated replacement for dwesely/submorse_controller. This adds a display and rotary encoder to let the user select from a wide variety of key options instead of just using physical toggle switches.

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

* Prep work:
  * Survey existing morse software to determine common keys (done: [morse trainers](https://docs.google.com/spreadsheets/d/1NgTxJTo4dAythpHvHk8G_OuLiSbL9fOsmyYwQumHkDQ))
  * Gather the hardware (done)
  * Map the pins (done)
  * Breadboard the hardware (done)
  * Blink (done)
* Set up VSCode project with latest repositories:
  * cnlohr/ch32fun
  * cnlohr/rv003usb
  * ADBeta/CH32V00x_lib_i2c
  * shakir-abdo/ch32v003-eeprom
  * shakir-abdo/CH32V003j4m6-BUZZER
  * Blink using the new project (done)
* OLED development:
  * Display 4 lines of text with space for a cursor (done)
  * Display cursor shape at the start of each line, in a function (done)
  * Turn off display on timeout
* Rotary input:
  * Turn on display on rotary press
  * Enter "configuration mode" on rotary press (show cursor)
  * Change row on button press (indicated by a cursor)
  * Reset on last rotary button press (pulsing D- low in user-code? reboot?)
  * Cycle through characters on rotary spin (only when in "configuration mode")
  * Debounce rotary press
* EEPROM emulation:
  * Write values to EEPROM on button press
  * Read EEPROM on boot
* HID:
  * Send space on morse press
  * Send LMB on morse press
  * Debounce morse press
  * Read key from flash and send the key on morse press
  * Send end character after delay
* Buzzer (straight key only, stretch goal):
  * Try an active buzzer on key 1 with a switch to pull it out of the circuit
  * Refer to shakir-abdo/CH32V003j4m6-BUZZER to sound a passive buzzer on key down
  * Add buzzer modes (HID, HID+buzzer, buzzer only)
  * Add interface to the display to use the rotary controller to select passive buzzer frequency and mode
  * Save frequency to EEPROM
* Hardware:
  * Finalize/package the hardware (maybe a breakout for key 1 to trigger a light strip addon like [this](https://www.youtube.com/watch?v=K_W7lgTX-V4)?)
  * Update documentation (fritzing model?)
  * Make a case

## Needed pins:
  
 * VDD - VCC
 * VSS - GND
 * PD1 - SWIO
 * PD4 - USB D+
 * PD3 - USB D-
 * PC2 - Display SCL
 * PC1 - Display SDA
 * PC3 - Rotary button
 * PA2 - Rotary A
 * PA1 - Rotary B
 * PD5 - Key 1
 * PD6 - Key 2
 * PC7 - LED
 * PC4 - Passive Buzzer (maybe?)
