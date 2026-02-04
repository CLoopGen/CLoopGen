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
    for (i = 2; i < len; i++) {
        out[i] = (double)in[i] - factor * (double)in[i - 1] + 0.5 * (double)in[i - 2];
    }
}
