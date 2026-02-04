#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int min;
unsigned int max = 131072;
unsigned short count[16];

void init_vars() {
    min = 0;
    for (unsigned int i = 0; i < 16; i++) {
        count[i] = 0;
    }
    count[15] = 1;
}