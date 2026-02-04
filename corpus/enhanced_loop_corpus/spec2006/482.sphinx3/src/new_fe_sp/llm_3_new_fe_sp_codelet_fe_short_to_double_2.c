#include <stdio.h>

#include <inttypes.h>

typedef short int16;

extern int16 *in;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16 *in_ptr = in;
    double *out_ptr = out;
    for (i = 0; i < len; i++) {
        *out_ptr++ = (double)*in_ptr++;
    }
}
