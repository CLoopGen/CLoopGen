#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *ptr8;
char *value;
int i;

static uint8_t data[1 << 20]; // 1MB buffer
static char value_buffer[1 << 20];

void init_vars() {
    ptr8 = data;
    value = value_buffer;
    i = 0;

    // Fill data with non-terminating characters for most of it
    for (int j = 0; j < (1 << 20) - 100; j++) {
        ptr8[j] = 'a' + (j % 26);
    }

    // Place a space near the end to ensure loop terminates within bounds
    ptr8[(1 << 20) - 100] = ' ';
    ptr8[(1 << 20) - 99] = '/'; // Also provide alternative terminator

    // Ensure null terminator in value buffer for safety if used as string
    value_buffer[0] = '\0';
}