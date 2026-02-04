#include <stdio.h>

#include <inttypes.h>

extern unsigned long *out;
extern int i;
extern int out_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < out_len; i++) {
        out[i] = 0;
        for (j = 0; j < 4; j++) {
            out[i] += j * j;
        }
    }
}
