#include <stdio.h>
#include "sdkconfig.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_log.h"

#include "driver/gpio.h"
#include "MQ2/MQ2.h"
static const char *TAG = "MQ2";

#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE


void app_main()
{
    gpio_config_t GPIO_config = {};
    GPIO_config.pin_bit_mask = (1 << 2);          /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
    GPIO_config.mode = GPIO_MODE_OUTPUT;               /*!< GPIO mode: set input/output mode                     */
    GPIO_config.pull_up_en = GPIO_PULLUP_DISABLE;       /*!< GPIO pull-up                                         */
    GPIO_config.pull_down_en = GPIO_PULLDOWN_DISABLE;   /*!< GPIO pull-down                                       */
    GPIO_config.intr_type = GPIO_INTR_DISABLE;    

    gpio_config (&GPIO_config);
    uint8_t blink_led_state = 0;
    mq2_sensor();

    while (1)
    {
        gpio_set_level(2, blink_led_state);
        blink_led_state =! blink_led_state;        
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
    
}
