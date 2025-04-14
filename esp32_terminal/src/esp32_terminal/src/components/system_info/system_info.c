#include <stdio.h>
#include <string.h>
#include "system_info.h"
#include "esp_system.h"
#include "esp_timer.h"
#include "esp_heap_caps.h"
#include "nvs_flash.h"
#include "nvs.h"

#define STORAGE_NAMESPACE "sysinfo"
#define KEY_DEVICE_ID     "device_id"
#define DEFAULT_DEVICE_ID "ESP32-001"

static char device_id[32] = DEFAULT_DEVICE_ID;

static void load_device_id_from_nvs(void) {
    nvs_handle_t handle;
    esp_err_t err = nvs_open(STORAGE_NAMESPACE, NVS_READONLY, &handle);
    if (err == ESP_OK) {
        size_t len = sizeof(device_id);
        err = nvs_get_str(handle, KEY_DEVICE_ID, device_id, &len);
        nvs_close(handle);
        if (err != ESP_OK) {
            strcpy(device_id, DEFAULT_DEVICE_ID);
        }
    }
}

const char *system_info_get_device_id(void) {
    return device_id;
}

void system_info_set_device_id(const char *new_id) {
    strncpy(device_id, new_id, sizeof(device_id) - 1);
    device_id[sizeof(device_id) - 1] = '\0';

    nvs_handle_t handle;
    if (nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &handle) == ESP_OK) {
        nvs_set_str(handle, KEY_DEVICE_ID, device_id);
        nvs_commit(handle);
        nvs_close(handle);
    }
}

void system_info_print(void) {
    uint64_t uptime_ms = esp_timer_get_time() / 1000;
    size_t free_heap = heap_caps_get_free_size(MALLOC_CAP_8BIT);

    printf("=====================================\n");
    printf(" Device ID     : %s\n", system_info_get_device_id());
    printf(" Uptime        : %llu ms\n", uptime_ms);
    printf(" Free heap     : %u bytes\n", (unsigned int)free_heap);
    printf("=====================================\n");
}

__attribute__((constructor))
static void init_system_info(void) {
    nvs_flash_init();
    load_device_id_from_nvs();
}
