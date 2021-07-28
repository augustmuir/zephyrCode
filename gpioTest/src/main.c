#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

#define SLEEP_TIME_MS   1000
#define LED0_NODE DT_ALIAS(led0)

#define LED0	DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN	DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS	DT_GPIO_FLAGS(LED0_NODE, gpios)

void main(void)
{
  const struct device *dev;
	bool led_is_on = true;
	int ret;

	dev = device_get_binding(LED0);

	ret = gpio_pin_configure(dev, PIN, GPIO_OUTPUT_ACTIVE | FLAGS);

	while (true) {
		gpio_pin_set(dev, PIN, (int)led_is_on);
		led_is_on = !led_is_on;
		k_msleep(SLEEP_TIME_MS);
	}
  // struct device *dev;
  // dev = device_get_binding("gpio0");
  //
  // gpio_pin_configure(dev, 29, GPIO_OUTPUT_ACTIVE | FLAGS);
  // gpio_pin_configure(dev, 30, GPIO_OUTPUT_ACTIVE | FLAGS);
  //
  // while(true){
  //   k_sleep(K_SECONDS(1.5));
  //   gpio_pin_set(dev, 29, 0);
  //   gpio_pin_set(dev, 30, 0);
  //   k_sleep(K_SECONDS(1.5));
  //   gpio_pin_set(dev, 29, 1);
  //   gpio_pin_set(dev, 30, 1);
  // }
}
