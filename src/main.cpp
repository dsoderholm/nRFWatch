
#include <stdio.h>
#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <nrfx_saadc.h>

#define SLEEP_TIME_MS   1000

#define BACK_LIGHT 8

void main(void)
{
	const struct device * gpio_dev = device_get_binding("GPIO_0");
	const struct device * adc_dev = device_get_binding("ADC_0");

	nrfx_saadc_init(70);
	nrfx_saadc_channel_t ch_cfg = NRFX_SAADC_DEFAULT_CHANNEL_SE(NRF_SAADC_INPUT_AIN1, 0);
	/*ch_cfg.channel_config.resistor_p = NRF_SAADC_RESISTOR_DISABLED;
	ch_cfg.channel_config.resistor_n = NRF_SAADC_RESISTOR_DISABLED;
	ch_cfg.channel_config.gain = NRF_SAADC_GAIN1;
	ch_cfg.channel_config.reference = NRF_SAADC_REFERENCE_INTERNAL;
	ch_cfg.channel_config.acq_time = NRF_SAADC_ACQTIME_40US;
	ch_cfg.channel_config.mode = NRF_SAADC_MODE_SINGLE_ENDED;
	ch_cfg.channel_config.burst = NRF_SAADC_BURST_DISABLED;
	ch_cfg.pin_p = NRF_SAADC_INPUT_AIN1;
	ch_cfg.pin_n = NRF_SAADC_INPUT_DISABLED;
	ch_cfg.channel_index = 0;*/

	
	nrfx_saadc_channel_config(&ch_cfg);
	//nrfx_saadc_simple_mode_set();

	gpio_pin_configure(gpio_dev, 8, GPIO_OUTPUT);
	gpio_pin_set(gpio_dev, 8, 1);
	nrf_saadc_value_t buffer;
	uint16_t size = 1;
	nrfx_saadc_simple_mode_set(1, NRF_SAADC_RESOLUTION_10BIT, NRF_SAADC_OVERSAMPLE_4X, NULL);
	nrfx_saadc_buffer_set(&buffer, size);
	while (1) {
		
		//ADC_0
		(void)nrfx_saadc_mode_trigger();

		printf("test: %d", buffer);
		k_msleep(SLEEP_TIME_MS);
	}
}