#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *key;
unsigned int *plaintext;
unsigned char *p;
unsigned int i;
unsigned int j;
unsigned int value;

static unsigned char p_data[16];
static unsigned int key_data[4];
static unsigned int plaintext_data[4];

void init_vars() {
    key = key_data;
    plaintext = plaintext_data;
    p = p_data;
    i = 0;
    j = 0;
    value = 0;

    for (int idx = 0; idx < 16; idx++) {
        p_data[idx] = (unsigned char)(idx & 0xFF);
    }
    for (int idx = 0; idx < 4; idx++) {
        key_data[idx] = 0xCAFEBABE ^ (idx << 8);
    }
    for (int idx = 0; idx < 4; idx++) {
        plaintext_data[idx] = 0;
    }
}