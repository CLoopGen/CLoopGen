#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *uni;
extern int unilen;
extern int i;
extern char *asctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_limit = (unilen + 3) / 4;
    int inner_limit = 2;
    for (int o = 0; o < outer_limit; o++) {
        for (int i_idx = 0; i_idx < inner_limit; i_idx++) {
            int idx = (o * 2 + i_idx) * 2;
            if (idx < unilen) {
                asctmp[idx >> 1] = uni[idx];
            }
        }
    }
}
