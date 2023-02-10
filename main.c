#include <avr/io.h>
#include <avr/cpufunc.h>
#include <avr/pgmspace.h>
#include "usbsimple.h"

#define nop() _NOP()

/*** Device Descriptor ***/
static const uint8_t PROGMEM dev_des[] = {
	18,       /* bLength = 18, descriptor length in bytest */  
	0x01,     /* bDescriptorType = 0x01, Descriptor ID = 1 -> Device descriptor */
	0x00,0x02,/* bcdUSB = 0x0200 - USB 2.0 */
	0x00,     /* bDeviceClass = 0x00, class code defined on interface level */
	0x00,     /* bDeviceSubClass = 0x00 */
	0x00,     /* bDeviceProtocoll = 0x00 */
	64,       /* bMaxPacketSize = 64 */
	0xeb,0x03,/* idVendor = 0x03eb, Atmel Code given by usb.org */
	0x01,0x00,/* idProduct = 0x0001, Produkt ID */
	0x01,0x00,/* bcdDevice = 0x0100, Release number device */
	0x01,     /* iManufacturer = Index for string-descriptor manufacturer */
	0x02,     /* iProduct = Index for string-descriptor product */
	0x03,     /* iSerialNumber = Index for string-descriptor serial number */
	0x01      /* bNumConfigurations = 1, Number of available configurations */
};     

/*** Configurations Descriptor ***/
static const uint8_t PROGMEM conf_des[] =  {
	9,        /* bLength = 9, descriptor length in bytes */
	0x02,     /* bDescriptorType = 0x02, Descriptor ID = 2 -> Configuration descriptor */
	18,0,     /* length of  Configuration = 9 + 9 + (7*endpoints) */
	0x01,     /* bNumInterfaces = 1 */
	0x01,     /* bConfigurationValue = 1, must not be 0 */
	0,        /* iConfiguration = 0, index for str.-descriptor configuration */
	0x80,     /* bmAttributes = 0x80,bus-powered, no remote wakeup Bit 7=1 */ 
	250,      /* MaxPower = 250(dezimal), means 250*2mA = 500mA */
};                    

/*** Interface Descriptor ***/
static const uint8_t PROGMEM intf_des[] = {
	9,        /* bLength = 0x09, length of descriptor in bytes */
        0x04,     /* bDescriptorType = 0x04, descriptor ID = 4 -> Interface descriptor*/
        0,        /* bInterfaceNumber = 0; */
        0,        /* bAlternateSetting = 0; */
        0,        /* bNumEndpoints = USB_Endpoints; */
        0xFF,     /* bInterfaceClass = 0xFF, classcode: custome (0xFF) */
        0xFF,     /* bInterfaceSubClass = 0xFF, subclasscode: custome (0xFF) */
        0xFF,     /* bInterfaceProtocol = 0xFF, protocoll code: custome (0xFF) */
        0,        /* iInterface = 0, Index for string descriptor interface */
};


static const uint8_t PROGMEM endp_des[] = {
        7,
        5,
        0,
        0,
        0,
        0,
        0
};


/*** Language Descriptor ***/      
static const uint8_t PROGMEM lang_des[] = {
	4,        /* bLength = 4, length of descriptor in bytes */
	0x03,     /* bDescriptorType = 0x03, Descriptor ID = 3 -> String descriptor */
	0x09,0x04 /* wLANGID[0] = 0x0409 = English USA (Supported Lang. Code 0) */
};

/*** Manufacturer Descriptor ***/          
static const uint8_t PROGMEM manu_des[] = {
	24,       /* bLength = 24, length of descriptor in bytes */
	0x03,     /* bDescriptorType = 0x03, Descriptor ID = 3 -> String descriptor */
	          /* bString = Unicode Encoded String (16 Bit!) */
	'B',0,'r',0,'i',0,'g',0,'h',0,'t',0,'l',0,'i',0, 'g', 0, 'h', 0, 't', 0,
};        

/*** Product Descriptor ***/       
static const uint8_t PROGMEM prod_des[] = {
	22,       /* bLength = 0x22, length of descriptor in bytes */
	0x03,     /* bDescriptorType = 0x03, Descriptor ID = 3 -> String descriptor */
                  /* bString = Unicode Encoded String (16 Bit!)*/
	'T',0,'e',0,'s',0,'t',0,'d',0,'e',0,'v',0,'i',0,'c',0,'e',0
};        

/*** Serial Descriptor ***/      
static const uint8_t PROGMEM seri_des[] = {
	10,       /* bLength = 0x12, length of descriptor in bytes */
	0x03,     /* bDescriptorType = 0x03, Descriptor ID = 3 -> String descriptor */
		  /* bString = Unicode Encoded String (16 Bit!) */
	'1',0,'2',0,'3',0,'4',0,
};

void setup() {

	usb_init_device();
	usb_config_endpoint(0);

}

void loop(){

	nop();
	nop();

}

int main(void) {

	setup();

	while (1) {
		loop();
	}

}
