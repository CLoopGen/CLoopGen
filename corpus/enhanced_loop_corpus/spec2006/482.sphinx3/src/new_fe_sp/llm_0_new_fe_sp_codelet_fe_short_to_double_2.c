#include <stdio.h>

#include <inttypes.h>

typedef short int16;

extern int16 *in;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < 1; j++) {
            out[i] = (double)in[i];
        }
    }
}
