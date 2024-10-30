#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#include "driver/gpio.h"

#include "driver/adc.h"

void app_main(void)
{
    gpio_set_direction(5, GPIO_MODE_OUTPUT);  // LED 1
    gpio_set_direction(GPIO_NUM_17, GPIO_MODE_INPUT); // Button 2
    int button2 = 0;
    int pressCount = 0;

    while (1) {
        button2 = gpio_get_level(GPIO_NUM_17);
        
        if (button2 == 1)
        {
            gpio_set_level(5, 1); // LED ON
            pressCount++; // เพิ่มนับจำนวนการกด
            printf("Button pressed %d times\n", pressCount);
            vTaskDelay(1000 / portTICK_PERIOD_MS); // หยุดรอ 1 วินาทีเพื่อหลีกเลี่ยงการนับซ้ำ
        }
        else
        {
            gpio_set_level(5, 0); // LED OFF
        }

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
