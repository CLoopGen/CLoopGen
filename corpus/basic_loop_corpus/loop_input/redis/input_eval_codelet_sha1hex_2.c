#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *digest;
unsigned char hash[20];
char *cset;
int j;

void init_vars() {
    digest = malloc(40);
    cset = malloc(16);
    for (int i = 0; i < 16; i++) {
        cset[i] = "0123456789abcdef"[i];
    }
    for (int i = 0; i < 20; i++) {
        hash[i] = rand();
    }
}

void loop();