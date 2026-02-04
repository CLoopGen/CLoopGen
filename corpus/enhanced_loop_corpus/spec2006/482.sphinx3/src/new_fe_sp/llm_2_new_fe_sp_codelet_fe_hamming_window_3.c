#include <stdio.h>

#include <inttypes.h>

extern double *in;
extern double *window;
extern int in_len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < in_len; i += stride) {
        if (i + 1 < in_len) {
            in[i] *= window[i];
            in[i + 1] *= window[i + 1];
        } else {
            in[i] *= window[i];
        }
    }
}
