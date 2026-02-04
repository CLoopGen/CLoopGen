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

    size_t size = sizeof(data);
    for (size_t j = 0; j < size - 1; j++) {
        ptr8[j] = 'a' + (j % 26);
    }
    ptr8[size - 1] = '\''; 
}