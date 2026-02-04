#include <stdio.h>

#include <inttypes.h>

typedef short int16;

extern int16 *in;
extern double *out;
extern int len;
extern float factor;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 1) {
        i = 1;
        for (; i < len; i++) {
            out[i] = (double)in[i] - factor * (double)in[i - 1];
        }
    }
}
