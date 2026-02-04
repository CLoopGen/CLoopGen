#include <stdio.h>

#include <inttypes.h>

extern unsigned long *out;
extern int i;
extern int out_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < out_len; i++) {
        if (!(i & 1)) {
            out[i] = 0;
        } else {
            out[i] = 0;
        }
    }
}
