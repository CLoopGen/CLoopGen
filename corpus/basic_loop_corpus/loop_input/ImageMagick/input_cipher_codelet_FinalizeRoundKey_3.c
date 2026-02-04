#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *ciphertext;
unsigned int *key;
unsigned char *p;
unsigned int i;
unsigned int j;
unsigned int value;

static unsigned int ciphertext_data[4];
static unsigned int key_data[4];
static unsigned char p_data[16];

void init_vars() {
    ciphertext = ciphertext_data;
    key = key_data;
    p = p_data;

    for (i = 0; i < 4; i++) {
        ciphertext[i] = 0xDEADBEEF ^ (i * 0x12345678);
        key[i] = 0xBAADF00D ^ (i * 0x87654321);
    }

    i = 0;
    j = 0;
    value = 0;
}