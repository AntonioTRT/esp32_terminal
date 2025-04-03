#include <stdio.h>
#include <string.h>
#include "cmd_parser.h"

void cmd_parser_handle(const char *input) {
    if (strcmp(input, "help") == 0) {
        printf("Comandos disponibles: help, echo, etc.\n");
    } else if (strncmp(input, "echo ", 5) == 0) {
        printf("ECO: %s\n", input + 5);
    } else {
        printf("Comando no reconocido: %s\n", input);
    }
}
