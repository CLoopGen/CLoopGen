#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *pass;
size_t passlen;
unsigned char *p;
size_t Plen;
size_t i;

static unsigned char *pass_storage;
static unsigned char *p_storage;

void init_vars() {
    passlen = 64;
    Plen = 1024 * 256; // ~256KB data, should run in ~0.01s on modern CPU

    pass_storage = (unsigned char*)malloc(passlen * sizeof(unsigned char));
    p_storage = (unsigned char*)malloc(Plen * sizeof(unsigned char));

    for (size_t j = 0; j < passlen; j++) {
        pass_storage[j] = (unsigned char)(j * j + 3);
    }

    pass = pass_storage;
    p = p_storage;
}