#include <stdio.h>

#include <inttypes.h>

typedef short int16;

extern int16 *in;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2)
        out[i] = (double)in[i];
}
