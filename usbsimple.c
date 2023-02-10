#include <avr/io.h>
#include <avr/interrupt.h> 
#include "usbsimple.h"

void usb_setup_endpoint(uint8_t endpoint) {
    
}

void usb_init_endpoint(uint8_t endpoint, uint8_t type, uint8_t size){
    UENUM = endpoint;
    UECONX = (1<<EPEN);
    UECFG0X = type;
    UECFG1X = size;
    UEIENX = (1<<RXSTPE); //Enable Received SETUP Interrupt
}

void usb_init_device(){

    //USB Hardware
    UHWCON = (1<<UVREGE); //Enable the USB pad regulator

    //USB Controller
    USBCON = ((1<<USBE) | (1<<FRZCLK) | (1<<OTGPADE)); //Enable USB Controller, Freeze Clock, VBUS Pad Enable (USB power)

    //PLL
    PLLCSR |= (1<<PINDIV); //Set PLL Input Prescaler for 16 MHz
    PLLCSR |= (1<<PLLE); //Enable PLL 
    while (!(PLLCSR &(1<<PLOCK))); //Wait for PLL to lock 

    //USB Clock
    USBCON &= ~(1 << FRZCLK); //Start USB clock
    
    //USB Attach
    UDCON &= ~((1<<LSM) | (1<<DETACH)); //Set full speed mode, attach device
    
    //USB Interrupts
    UDIEN = (1<<EORSTE); //Enable interrupts for EOR (End of Reset)   

}

void usb_config_endpoint(uint8_t endpoint){

}

ISR(USB_GEN_vect) {

        //Check if device was reseted
	if (UDINT & (1<<EORSTI)) {
		
		//Interrupt reset
		UDINT &= ~(1<<EORSTI); //Clear EOR interrupt
		
		//USB Endpoint init
		usb_init_endpoint(0, EP_TYPE_CONTROL, EP_SIZE_64_ONE_BANK);    
		 
	}
	
}

ISR(USB_COM_vect) {
	
	//Check usb endpoint interrupt received
	switch (UEINT) {
	case (1<<EPINT0): 
		//Is endpoint 0
		UENUM = 0; //Select endpoint 0
	   	//Check interrupt type - setup
	   	if (UEINTX & (1<<RXSTPI))
		   	usb_setup_endpoint(0);
	   	break;
	default: 
                break;
	}
	
}
