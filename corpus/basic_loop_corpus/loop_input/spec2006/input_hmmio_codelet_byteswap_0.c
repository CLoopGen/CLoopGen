#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *swap;
int nbytes;
int x;
char byte;

void init_vars() {
    nbytes = 131072; // 128 KB data size for ~0.01 sec runtime on modern CPU
    swap = (char *)malloc(nbytes);
    if (!swap) {
        exit(1);
    }
    for (int i = 0; i < nbytes; i++) {
        swap[i] = (char)(i & 0xFF);
    }
}