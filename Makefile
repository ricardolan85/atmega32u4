PROJECT = atmega32u4

CC = avr-gcc
CFLAGS = -Os -DF_CPU=16000000UL -D__AVR_ATmega32U4__ -mmcu=atmega32u4
SRCS = main.c usbsimple.c
OBJS = main.o usbsimple.o

all: $(PROJECT).elf

$(PROJECT).elf: ${OBJS}
	$(CC) -o $(PROJECT).elf $(OBJS) $(CFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

size: $(PROJECT).elf
	avr-size --format=avr --mcu=atmega32u4 $(PROJECT).elf

hex: $(PROJECT).elf
	avr-objcopy -O ihex $(PROJECT).elf $(PROJECT).hex

dump: $(PROJECT).elf
	avr-objdump -d $(PROJECT).elf > $(PROJECT).dump

clean:
	del *.o
	del *.hex 
	del *.elf
	del *.dump
