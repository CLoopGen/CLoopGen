#include <stdint.h>
#include <string.h>

uint8_t *key;
size_t len;
uint64_t hash;
size_t i;

static uint8_t key_storage[131072]; // 128KB

void init_vars() {
    len = 131072;
    hash = 0;
    i = 0;
    for (size_t j = 0; j < len; j++) {
        key_storage[j] = (uint8_t)(j & 0xFF);
    }
    key = key_storage;
}