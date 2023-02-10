#define EP_TYPE_CONTROL 	0b00000000 //type controle
#define EP_TYPE_ISOCHRONOUS 	0b01000000 //type isochronous
#define EP_TYPE_BULK		0b10000000 //type bulk
#define EP_TYPE_INTERRUPT	0b11000000 //type interrupt

#define EP_SIZE_64_ONE_BANK	0b00110010 //64 bytes, one bank, alloc

void usb_init_device();
void usb_config_endpoint(uint8_t endpoint);