#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *iv;
uint8_t *salt;

int i;

static uint8_t iv_storage[14];
static uint8_t salt_storage[14];

void init_vars() {
    iv = iv_storage;
    salt = salt_storage;

    for (int j = 0; j < 14; j++) {
        iv[j] = rand() & 0xFF;
        salt[j] = rand() & 0xFF;
    }
}