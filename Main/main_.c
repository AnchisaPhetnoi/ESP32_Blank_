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
    int ledState = 0;

    while (1) {
        button2 = gpio_get_level(GPIO_NUM_17);
        
        if (button2 == 1)
        {
            ledState = !ledState; // สลับสถานะ LED
            gpio_set_level(5, ledState); // ตั้งค่า LED ตามสถานะ
            printf("LED State = %d\n", ledState);
            vTaskDelay(1000 / portTICK_PERIOD_MS); // หยุดรอ 1 วินาทีเพื่อหลีกเลี่ยงการกดซ้ำ
        }

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

