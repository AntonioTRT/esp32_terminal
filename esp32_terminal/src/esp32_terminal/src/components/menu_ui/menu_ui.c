#include <stdio.h>
#include "menu_ui.h"

void menu_ui_show(void) {
    printf("\n=====================================\n");
    printf("      ESP32 TERMINAL INTERACTIVA     \n");
    printf("=====================================\n");
    printf("ID del dispositivo : ESP32-001\n");
    printf("SSID conectado     : (por implementar)\n");
    printf("Hora actual        : (por implementar)\n");
    printf("-------------------------------------\n");
    printf("Comandos disponibles:\n");
    printf("- wifi connect <ssid> <pass>\n");
    printf("- wifi status\n");
    printf("- help\n");
    printf("-------------------------------------\n");
    printf("Ingrese comando:\n> ");
}
