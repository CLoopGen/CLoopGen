#include <stdio.h>

#include <inttypes.h>

extern char outbuf[16];
extern char *bp2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int idx = i * 4 + j;
            outbuf[idx] ^= bp2[idx];
        }
    }
}
