#include <stdio.h>

#include <inttypes.h>

typedef short int16;

extern int16 *in;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        out[i] = (double)in[i];
        if (in[i] < 0)
            out[i] = -out[i];  // Make positive (redundant cast, but introduces control)
    }
}
