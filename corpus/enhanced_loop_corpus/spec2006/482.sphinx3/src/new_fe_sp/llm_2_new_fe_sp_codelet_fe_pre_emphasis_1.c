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
for (i = 2; i < len; i += 2) {
    out[i] = (double)in[i] - factor * (double)in[i - 1];
    out[i-1] = (double)in[i-1] - factor * (double)in[i - 2];
}
}
