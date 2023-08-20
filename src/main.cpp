
#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>


#define SLEEP_TIME_MS   1000

#define BACK_LIGHT 8

void main(void)
{
	const struct device * dev = device_get_binding("GPIO_0");
    gpio_pin_configure(dev, 7, GPIO_OUTPUT);
	gpio_pin_configure(dev, 8, GPIO_OUTPUT);
	gpio_pin_configure(dev, 9, GPIO_OUTPUT);

	while (1) {
		gpio_pin_set(dev, 7, 0);
		gpio_pin_set(dev, 8, 0);
		gpio_pin_set(dev, 9, 0);
		k_msleep(SLEEP_TIME_MS);
	}
}