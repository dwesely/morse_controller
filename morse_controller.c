/*
 * Morse key controller
 * 
 */
 
//
#define SSD1306_128X32

#include "ch32fun.h"
#include <stdio.h>
#include "ssd1306_i2c.h"
#include "ssd1306.h"

void display_current_settings(int row)
{
	if(row==0)
	{
		// No row selected, do not display a cursor
	}
	// show cursor at specified row
	// write current settings on each row
	//     Key1:
	//     Key2:
	//     End:
	//     End Delay: . ms

}

void config_mode()
{
	// Device is now in config mode
	
	// display current settings at row 1
	
	// listen for rotary encoder changes
	
	// change values for current row when rotary encoder changes
	
	// listen for rotary push
	
	// increment row up 1 on rotary push
	
	// when row > 4, write the current values to flash, and reboot
}

int main()
{
	// initialize HID using saved values (or defaults for first boot)
	
	// display current settings and time out after X seconds
	
	// listen for HID requests
	
	// listen for keys
	
	// trigger HID on key down
	
	// listen for rotary push
	
	// enter config_mode on rotary push
}

void usb_handle_user_data()
{
	// 
}

void usb_handle_user_in_request()
{
	//
}