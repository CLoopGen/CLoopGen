#include <stdio.h>

#include <inttypes.h>

typedef short int16;

extern int16 *in;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        i = 0;
        for (;;) {
            out[i] = (double)in[i];
            i++;
            if (i >= len) break;
        }
    }
}
