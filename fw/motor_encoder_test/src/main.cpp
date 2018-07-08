#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/portmacro.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/periph_ctrl.h"
#include "driver/gpio.h"
#include "driver/pcnt.h"
#include "esp_attr.h"
#include "esp_log.h"
#include "soc/gpio_sig_map.h"
#include "esp32-hal-adc.h"

#include <driver/adc.h>
#include "esp_system.h"
#include "driver/spi_master.h"
#include "motorEncoder.h"

#define MEASURE_TASK_PERIOD 10     //in [ms]

static void gpio_task_example(void* arg)
{
    gpio_num_t io_num;
    for(;;) {
        if(xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY)) {
            printf("GPIO[%d] intr, val: %d\n", io_num, gpio_get_level(io_num));
        }
    }
}

extern "C" {
    void app_main(void);
}

void taskOne(void * parameter)
{
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = MEASURE_TASK_PERIOD / portTICK_PERIOD_MS;
    xLastWakeTime = xTaskGetTickCount();

    int16_t counterEngine[ENGINES_NUMBER] = {0, };
    float freqWheel[ENGINES_NUMBER] = {0.0, };

    for( ;; )
    {
        // Wait for the next cycle.
        vTaskDelayUntil( &xLastWakeTime, xPeriod );

        // Perform action here.
        updateWheelCounters(counterEngine, freqWheel, MEASURE_TASK_PERIOD);
        printf("Current wheel freqency in time %dms :", millis());
        for(uint8_t i = 0; i < ENGINES_NUMBER; ++i)
        {
            printf("%.1f Hz, ", freqWheel[i]);
        }
        printf("\n");
    }
}

void app_main()
{
    //create a queue to handle gpio event from isr
    gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));

    initWheelCounters();
    //start gpio task
    xTaskCreate(gpio_task_example, "gpio_task_example", 2048, NULL, 10, NULL);

    xTaskCreate(&taskOne, "taskOne", 2048, NULL, 5, NULL);

    hookInterruptPins();

    while (1) {
        delay(10);
    }
}