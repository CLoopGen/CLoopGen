#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern float *out;
extern int size;
extern int n;
extern float dot;
extern  float *best_hist_ptr;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (n = 0; n < size; n++)
    out[n] = best_hist_ptr[n] + dot * (in[n] - best_hist_ptr[n]);

}
