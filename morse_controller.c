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


#define PIN_LED PC7


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
	
	SystemInit();

	funGpioInitAll(); // Enable GPIOs
	
	funPinMode( PIN_LED,     GPIO_Speed_10MHz | GPIO_CNF_OUT_PP ); // Set PIN_LED to output


	funDigitalWrite( PIN_LED, FUN_HIGH ); // Turn on PIN_LED
	Delay_Ms( 500 );
	funDigitalWrite( PIN_LED,     FUN_LOW );  // Turn off PIN_LED

	// initialize HID using saved values (or defaults for first boot)
	
	// display current settings and time out after X seconds

	// init i2c and oled
	Delay_Ms( 100 );	// give OLED some more time
	printf("initializing i2c oled...");

	if(!ssd1306_i2c_init())
	{
		ssd1306_init();
		printf("done.\n\r");
		
		ssd1306_setbuf(0);

		ssd1306_drawstr_sz(8,0, "Key1: [Space]", 1, fontsize_8x8);
		ssd1306_drawstr_sz(8,8, "Key2: ", 1, fontsize_8x8);
		ssd1306_drawstr_sz(8,16, "End: E", 1, fontsize_8x8);
		ssd1306_drawstr_sz(8,24, "End Delay: 100ms", 1, fontsize_8x8);
		ssd1306_drawstr_sz(0,0, ">", 1, fontsize_8x8);

		ssd1306_refresh();
	
		Delay_Ms(2000);
		ssd1306_setbuf(0);
	}
	else
		printf("failed.\n\r");
	
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