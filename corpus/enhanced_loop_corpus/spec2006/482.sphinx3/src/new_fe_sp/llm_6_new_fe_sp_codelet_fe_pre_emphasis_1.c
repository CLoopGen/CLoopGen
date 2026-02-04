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
    double prev_in = (double)in[0];
    for (i = 1; i < len; i++) {
        double current_in = (double)in[i];
        out[i] = current_in - factor * prev_in;
        prev_in = current_in;
    }
}
