#pragma once

// Inicia el loop principal de entrada de comandos.
// Por ahora lee líneas por UART, pero en el futuro podrá recibir
// eventos de botones físicos, pantalla táctil, teclado, etc.
void input_start_loop(void);
