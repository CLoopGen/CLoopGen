#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
int sLen;
unsigned char *salt;
unsigned char *p;

static unsigned char *salt_storage;
static unsigned char *p_storage;

void init_vars() {
    size_t data_size = 1024 * 256; // 256KB, target ~0.01 sec on modern CPU
    sLen = (int)data_size;

    salt_storage = (unsigned char *)calloc(data_size, sizeof(unsigned char));
    p_storage = (unsigned char *)calloc(data_size, sizeof(unsigned char));

    if (!salt_storage || !p_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        salt_storage[idx] = (unsigned char)(idx & 0xFF);
        p_storage[idx] = (unsigned char)((idx + 31) & 0xFF);
    }

    salt = salt_storage;
    p = p_storage;
}