#include <stdio.h>

#include <inttypes.h>

extern unsigned long *out;
extern int i;
extern int out_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < out_len; i++) {
        for (j = 0; j < 1; j++) {
            out[i] = 0;
        }
    }
}
