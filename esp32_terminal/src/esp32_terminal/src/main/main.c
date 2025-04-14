#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    printf("iniciando... \n");
    vTaskDelay(pdMS_TO_TICKS(1000)); 
    printf("¡Mensaje 2!\n");
    vTaskDelay(pdMS_TO_TICKS(1000)); 
    printf("\033[2K\r"); 
    printf("¡Mensaje 3!\n");
    vTaskDelay(pdMS_TO_TICKS(1000)); 




}
