#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *swap;
int nbytes;
int x;
char byte;

void init_vars() {
    nbytes = 134217728; // 128 MB, adjust for ~0.01 sec on modern CPU
    swap = (char *)malloc(nbytes);
    if (!swap) {
        nbytes = 0;
        return;
    }
    for (int i = 0; i < nbytes; i++) {
        swap[i] = (char)(i & 0xFF);
    }
}