#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *salt;
size_t saltlen;
unsigned char *p;
size_t Slen;
size_t i;

void init_vars() {
    saltlen = 16;
    salt = (unsigned char *)malloc(saltlen);
    for (size_t j = 0; j < saltlen; j++) {
        salt[j] = (unsigned char)(j * j + 3);
    }

    Slen = 524288; // ~512 KB, target ~0.01 sec on modern CPU
    p = (unsigned char *)malloc(Slen);

    i = 0;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}