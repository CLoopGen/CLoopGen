#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *ptr8;
char *value;
int i;

static uint8_t data[1 << 20]; // 1MB of input data
static char buffer[1 << 20];

void init_vars() {
    ptr8 = data;
    value = buffer;
    i = 0;

    size_t len = sizeof(data) - 1;
    for (size_t j = 0; j < len; j++) {
        if (j == 79) {
            data[j] = ')'; 
        } else {
            data[j] = 'A' + (j % 26);
        }
    }
    data[len] = 0;

    memset(buffer, 0, sizeof(buffer));
}