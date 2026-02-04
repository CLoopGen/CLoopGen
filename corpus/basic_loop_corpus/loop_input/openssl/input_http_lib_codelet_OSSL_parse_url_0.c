#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char *port;
char *port_end;

static char data_buffer[1024 * 128]; // 128KB buffer

void init_vars() {
    size_t i;
    // Fill the buffer with '0' to '9' characters to ensure long execution in the loop
    for (i = 0; i < sizeof(data_buffer) - 1; i++) {
        data_buffer[i] = '0' + (i % 10); // cycling digits '0' to '9'
    }
    data_buffer[sizeof(data_buffer) - 1] = '\0'; // null terminate

    // Initialize port to point to the start of the buffer
    port = data_buffer;
    port_end = NULL;
}