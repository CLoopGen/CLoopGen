#include <stdio.h>

#include <inttypes.h>

extern double *in;
extern double *window;
extern int in_len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < in_len; i++) {
        in[i] *= window[i];
        if (in[i] < 0.0) {
            in[i] = -in[i]; // Make positive if negative after multiplication
        }
    }
}
