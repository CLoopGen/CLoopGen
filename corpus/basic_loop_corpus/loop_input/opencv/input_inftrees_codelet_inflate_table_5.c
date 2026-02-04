#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int len;
unsigned short count[16];
unsigned short offs[16];

void init_vars() {
    len = 0;
    for (int i = 0; i < 16; i++) {
        count[i] = (unsigned short)(i * 1000 + 500);
        offs[i] = (unsigned short)(i * 2000);
    }
}