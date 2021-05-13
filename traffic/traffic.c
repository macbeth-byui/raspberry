#include "stdio.h"
#include "bcm2835.h"

#define GREEN    RPI_BPLUS_GPIO_J8_23
#define YELLOW   RPI_BPLUS_GPIO_J8_19
#define RED      RPI_BPLUS_GPIO_J8_21
    

int main()
{
    int status = 0;

    /* Initialize Drivers */
    status = bcm2835_init();

    if (status == 0)    
    {
        printf("Failed to initialize bcm2835 library.\n");
        return -1;
    }

    printf("bcm2835 library initialized.\n");

    /* Set GPIO Pins to Output */
    bcm2835_gpio_fsel(RED, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(YELLOW, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(GREEN, BCM2835_GPIO_FSEL_OUTP);

    /* Start by turning off all the lights */
    bcm2835_gpio_write(RED, LOW);
    bcm2835_gpio_write(YELLOW, LOW);
    bcm2835_gpio_write(GREEN, LOW);

    while (1) /* Run Forever */
    {
        printf("Change light GREEN for 3 Seconds\n\n");
        bcm2835_gpio_write(RED, LOW);
        bcm2835_gpio_write(GREEN, HIGH);
        bcm2835_delay(3000);

        printf("Change light YELLOW for 1 Second\n\n");
        bcm2835_gpio_write(GREEN, LOW);
        bcm2835_gpio_write(YELLOW, HIGH);
        bcm2835_delay(1000);

        printf("Change light RED for 3 Seconds\n\n");
        bcm2835_gpio_write(YELLOW, LOW);
        bcm2835_gpio_write(RED, HIGH);
        bcm2835_delay(3000);

    }

    /* Currently we will never run this code because the
       loop above runs forever ... oh well.  */

    status = bcm2835_close();

    printf("Close bcm2835 library (result=%d)\n", status);

    return 0;
}
   
