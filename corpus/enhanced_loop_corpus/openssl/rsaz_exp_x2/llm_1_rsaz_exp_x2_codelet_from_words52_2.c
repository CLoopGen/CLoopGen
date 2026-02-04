#include <stdio.h>

#include <inttypes.h>

extern unsigned long *out;
extern int i;
extern int out_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (out_len > 0) {
        i = 0;
        for (; i < out_len; ) {
            out[i] = 0;
            i++;
        }
    }
}
