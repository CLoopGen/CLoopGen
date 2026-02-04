#include <stdio.h>

#include <inttypes.h>

extern double *in;
extern double *window;
extern int in_len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (in_len > 0) {
    for (i = 0; i < in_len; i += 2) {
        in[i] *= window[i];
        if (i + 1 < in_len)
            in[i + 1] *= window[i + 1];
    }
}
}
