
#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>


#define SLEEP_TIME_MS   1000

#define BACK_LIGHT 8

void main(void)
{


	const struct device * dev = device_get_binding("GPIO_P");
    // configure the LED pin as output
    gpio_pin_configure(dev, BACK_LIGHT, GPIO_OUTPUT);

	while (1) {
		gpio_pin_toggle(dev, BACK_LIGHT);
		k_msleep(SLEEP_TIME_MS);
	}
}