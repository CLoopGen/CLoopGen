#include <stdio.h>

#include <inttypes.h>

extern short *inbuf;
extern int *num_used;
extern int ch;
extern short inbuf_old[2][5];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    for (i = 4; i >= 0; i--)
        inbuf_old[ch][4 - i] = inbuf[*num_used + i - 5];
}
