
//Name : Onkar Singh
//Roll no. : B13321
//Assignment : hw05

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <signal.h>    // Defines signal-handling functions (i.e. trap Ctrl-C)
#include "gpio.h"

// making global var and funcs
int goOn  = 1;

void signal_handler(int sig);

void signal_handler(int sig)
{
	printf("Ctrl-C pressed , exiting\n");
	goOn = 0;
}

int main(int argc, char const *argv[])
{

	//Declaring variables

    volatile void *gpio_addr;
    volatile unsigned int *gpio_oe_addr;
    volatile unsigned int *gpio_datain;
    volatile unsigned int *gpio_setdataout_addr;
    volatile unsigned int *gpio_cleardataout_addr;
    unsigned int reg;

    //for Ctrl-C

     signal(SIGINT, signal_handler);

     //open  dev/mem 

    int fd = open("/dev/mem", O_RDWR);

    printf("Mapping %X - %X (size: %X)\n", GPIO0_START_ADDR, GPIO0_END_ADDR, GPIO0_SIZE);
    gpio_addr = mmap(0, GPIO0_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO0_START_ADDR);

    //Setting offset for pins from the .h file

    gpio_oe_addr           = gpio_addr + GPIO_OE;
    gpio_datain            = gpio_addr + GPIO_DATAIN;
    gpio_setdataout_addr   = gpio_addr + GPIO_SETDATAOUT;
    gpio_cleardataout_addr = gpio_addr + GPIO_CLEARDATAOUT;
   
    //Check if mmap worked at that address.

    if(gpio_addr == MAP_FAILED) {
    printf("Unable to map GPIO\n");
    exit(1);
	}

    printf("GPIO mapped to %p\n", gpio_addr);
    printf("GPIO OE mapped to %p\n", gpio_oe_addr);
    printf("GPIO SETDATAOUTADDR mapped to %p\n", gpio_setdataout_addr);
    printf("GPIO CLEARDATAOUT mapped to %p\n", gpio_cleardataout_addr);

    *gpio_oe_addr0 &= GPIO_03;
	*gpio_oe_addr0 &= ~GPIO_07;    

    printf("Button at GPIO_03 controls LED at GPIO_07\n");

    while(goOn) {
    	if(*gpio_datain & GPIO_03) {
            *gpio_setdataout_addr= GPIO_07;
    	} else {
            *gpio_cleardataout_addr = GPIO_07;
    	}
    }

	//Un map or else bone does strange things later! You must reboot it without it.

    munmap((void *)gpio_addr, GPIO0_SIZE);
    close(fd);
    return 0;
}

