#include <stdio.h>

#include <inttypes.h>

extern short *inbuf;
extern int *num_used;
extern int ch;
extern short inbuf_old[2][5];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        inbuf_old[ch][i] = inbuf[*num_used + i - 5];
        if (inbuf_old[ch][i] == 0) {
            continue;
        }
    }
}
