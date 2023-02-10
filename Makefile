CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega32u4
SOURCES = main.c usbsimple.c
TARGET = usb_avr

all:
	avr-gcc -o ${TARGET}.elf ${SOURCES} ${CFLAGS}
	avr-objdump -d ${TARGET}.elf > ${TARGET}.dump
	avr-objcopy -O ihex ${TARGET}.elf ${TARGET}.hex
	avr-size --format=avr --mcu=atmega32u4 ${TARGET}.elf

clean:
	rm -rf *.hex *.elf *~ ${TARGET}.dump
