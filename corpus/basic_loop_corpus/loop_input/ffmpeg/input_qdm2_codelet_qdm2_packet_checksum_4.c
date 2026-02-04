#include <stdint.h>
#include <stdlib.h>

uint8_t *data;
int length;
int value;
int i;

void init_vars() {
    length = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    data = (uint8_t *)malloc(length * sizeof(uint8_t));
    if (!data) {
        exit(1);
    }
    for (int j = 0; j < length; j++) {
        data[j] = (uint8_t)(j & 0xFF);
    }
    value = 1000000;
    i = 0;
}