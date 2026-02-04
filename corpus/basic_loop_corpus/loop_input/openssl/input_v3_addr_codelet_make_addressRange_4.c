#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *max;
int length;
int i;

void init_vars() {
    length = 131072; // 128 KB of data

    max = (unsigned char *)malloc(length * sizeof(unsigned char));
    if (!max) {
        length = 0;
        return;
    }

    memset(max, 255, length);
}

void loop(); 

__attribute__((constructor))
static void constructor() {
    init_vars();
}