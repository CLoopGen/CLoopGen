#include <stdio.h>

#include <inttypes.h>

extern short *inbuf;
extern int *num_used;
extern int ch;
extern short inbuf_old[2][5];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2, unrolled pattern with bounds check)
    for (i = 0; i < 5; i += 2) {
        inbuf_old[ch][i] = inbuf[*num_used + i - 5];
        if (i + 1 < 5)
            inbuf_old[ch][i + 1] = inbuf[*num_used + (i + 1) - 5];
    }
}
