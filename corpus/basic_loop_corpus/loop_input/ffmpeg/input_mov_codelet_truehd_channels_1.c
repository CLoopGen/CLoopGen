#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t thd_chancount[13];
int chanmap;
int channels;
int i;

void init_vars() {
    for (int j = 0; j < 13; j++) {
        thd_chancount[j] = (uint8_t)(j * 7 % 128);
    }
    chanmap = 0x1FFF; // Ensures all 13 bits can be accessed
    channels = 0;
    i = 0;
}