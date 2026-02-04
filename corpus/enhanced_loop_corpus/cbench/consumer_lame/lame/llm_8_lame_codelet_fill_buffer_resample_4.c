#include <stdio.h>

#include <inttypes.h>

extern short *inbuf;
extern int *num_used;
extern int ch;
extern short inbuf_old[2][5];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 10; i += 2) {
        j = *num_used + i - 5;
        inbuf_old[ch][i/2] = inbuf[j];
        inbuf_old[ch][(i/2)+1] = inbuf[j+1] + 1; // Extra arithmetic and access
    }
}
