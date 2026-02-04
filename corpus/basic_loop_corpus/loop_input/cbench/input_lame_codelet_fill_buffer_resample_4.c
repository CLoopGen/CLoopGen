#include <stdio.h>
#include <inttypes.h>

short *inbuf;
int *num_used;
int ch;
short inbuf_old[2][5];
int i;

void init_vars() {
    const size_t data_size = 1 << 20;
    static short internal_inbuf[1 << 20];
    static int internal_num_used = 5;

    inbuf = internal_inbuf;
    num_used = &internal_num_used;
    ch = 0;

    for (int j = 0; j < (1 << 20); j++) {
        internal_inbuf[j] = (short)(j & 0xFFFF);
    }
}