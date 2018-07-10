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

extern "C" {
    void app_main(void);
}
void taskOne(void * parameter)
{
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = MEASURE_TASK_PERIOD / portTICK_PERIOD_MS;
    xLastWakeTime = xTaskGetTickCount();

    int16_t counterEngine[COUNTERS_NUMBER] = {0, };
    float freqWheel[COUNTERS_NUMBER] = {0.0, };

    for( ;; )
    {
        // Wait for the next cycle.
        vTaskDelayUntil( &xLastWakeTime, xPeriod );

        // Perform action here.
        /*updateWheelCounters(counterEngine, freqWheel, MEASURE_TASK_PERIOD);
        printf("Current wheel freqency in time %dms :", millis());
        for(uint8_t i = 0; i < COUNTERS_NUMBER; ++i)
        {
            printf("%.1f Hz, ", freqWheel[i]);
        }
        printf("\n");*/
        int16_t counter = 0;
        pcnt_get_counter_value(pcntUnits[1], &counter);
        printf("Counter1 val: %d, tDiffUs: %d\n", counter, counterTimeDiff[1]);
    }
}

void app_main()
{
    initWheelCounters();

    xTaskCreate(&taskOne, "taskOne", 2048, NULL, 5, NULL);

    hookInterruptPins();

    while (1) {
        delay(10);
    }
}