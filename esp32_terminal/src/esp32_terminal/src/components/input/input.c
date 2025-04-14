#include <stdio.h>
#include <string.h>
#include "input.h"
#include "cmd_parser.h"

// 🧠 Este módulo centraliza la entrada del usuario al sistema.
// Por ahora utiliza UART (stdin) para leer comandos línea por línea,
// pero está diseñado para que en el futuro pueda integrarse con:
// - Entrada por botones físicos (GPIOs)
// - Entrada táctil o pantallas
// - Menús con navegación por teclas (flechas)
// - Interfaz web o remota

#define MAX_LINE_LEN 128

void input_start_loop(void) {
    char line[MAX_LINE_LEN];

    while (1) {
        printf("> "); // prompt simple

        if (fgets(line, sizeof(line), stdin) != NULL) {
            // eliminar salto de línea si existe
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }

            if (strlen(line) > 0) {
                cmd_parser_handle(line);
            }
        }
    }
}
