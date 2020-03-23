#include "stdio.h"
#include "bcm2835.h"

void display_gpio(const char* name, const uint8_t pin)
{
    uint8_t level = bcm2835_gpio_lev(pin);
    printf("GPIO (%s, %d) : %d\n", name, pin, level);
}
    

int main()
{
    int status = 0;

    status = bcm2835_init();

    if (status == 0)    
    {
        printf("Failed to initialize bcm2835 library.\n");
        return -1;
    }

    printf("bcm2835 library initialized.\n");

    display_gpio("RPI_BPLUS_GPIO_J8_03", RPI_BPLUS_GPIO_J8_03);
    display_gpio("RPI_BPLUS_GPIO_J8_05", RPI_BPLUS_GPIO_J8_05);
    display_gpio("RPI_BPLUS_GPIO_J8_07", RPI_BPLUS_GPIO_J8_07);
    display_gpio("RPI_BPLUS_GPIO_J8_08", RPI_BPLUS_GPIO_J8_08);
    display_gpio("RPI_BPLUS_GPIO_J8_10", RPI_BPLUS_GPIO_J8_10);
    display_gpio("RPI_BPLUS_GPIO_J8_11", RPI_BPLUS_GPIO_J8_11);
    display_gpio("RPI_BPLUS_GPIO_J8_12", RPI_BPLUS_GPIO_J8_12);
    display_gpio("RPI_BPLUS_GPIO_J8_13", RPI_BPLUS_GPIO_J8_13);
    display_gpio("RPI_BPLUS_GPIO_J8_15", RPI_BPLUS_GPIO_J8_15);
    display_gpio("RPI_BPLUS_GPIO_J8_16", RPI_BPLUS_GPIO_J8_16);
    display_gpio("RPI_BPLUS_GPIO_J8_18", RPI_BPLUS_GPIO_J8_18);
    display_gpio("RPI_BPLUS_GPIO_J8_19", RPI_BPLUS_GPIO_J8_19);
    display_gpio("RPI_BPLUS_GPIO_J8_21", RPI_BPLUS_GPIO_J8_21);
    display_gpio("RPI_BPLUS_GPIO_J8_22", RPI_BPLUS_GPIO_J8_22);
    display_gpio("RPI_BPLUS_GPIO_J8_23", RPI_BPLUS_GPIO_J8_23);
    display_gpio("RPI_BPLUS_GPIO_J8_24", RPI_BPLUS_GPIO_J8_24);
    display_gpio("RPI_BPLUS_GPIO_J8_26", RPI_BPLUS_GPIO_J8_26);
    display_gpio("RPI_BPLUS_GPIO_J8_29", RPI_BPLUS_GPIO_J8_29);
    display_gpio("RPI_BPLUS_GPIO_J8_31", RPI_BPLUS_GPIO_J8_31);
    display_gpio("RPI_BPLUS_GPIO_J8_32", RPI_BPLUS_GPIO_J8_32);
    display_gpio("RPI_BPLUS_GPIO_J8_33", RPI_BPLUS_GPIO_J8_33);
    display_gpio("RPI_BPLUS_GPIO_J8_35", RPI_BPLUS_GPIO_J8_35);
    display_gpio("RPI_BPLUS_GPIO_J8_36", RPI_BPLUS_GPIO_J8_36);
    display_gpio("RPI_BPLUS_GPIO_J8_37", RPI_BPLUS_GPIO_J8_37);
    display_gpio("RPI_BPLUS_GPIO_J8_38", RPI_BPLUS_GPIO_J8_38);
    display_gpio("RPI_BPLUS_GPIO_J8_40", RPI_BPLUS_GPIO_J8_40);

    status = bcm2835_close();

    printf("Close bcm2835 library (result=%d)\n", status);

    return 0;
}
   

