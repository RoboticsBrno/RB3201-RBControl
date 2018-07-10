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

    MotorEncoder encoder1(1);

    for( ;; )
    {
        // Wait for the next cycle.
        vTaskDelayUntil( &xLastWakeTime, xPeriod );
        // Perform action here.
        printf("Counter1 val: %d, tDiffUs: %d, freqency: %.2f\n", encoder1.getPCNT(), encoder1.getTimeDiff(), encoder1.getFrequency());
    }
}

void app_main()
{
    xTaskCreate(&taskOne, "taskOne", 2048, NULL, 5, NULL);

    while (1) {
        delay(10);
    }
}