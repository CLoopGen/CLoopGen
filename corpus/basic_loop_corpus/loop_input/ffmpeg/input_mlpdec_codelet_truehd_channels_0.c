#include <stdint.h>
#include <stdlib.h>

uint8_t thd_chancount[13];
int chanmap;
int channels;
int i;

void init_vars() {
    for (int j = 0; j < 13; j++) {
        thd_chancount[j] = (uint8_t)(j * 7 % 128);
    }
    chanmap = 0x1FFF;
    channels = 0;
    i = 0;
}