#include <stdio.h>

#include <inttypes.h>

extern double *in;
extern double *window;
extern int in_len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    double temp = 1.0;
    for (j = 0; j < in_len; j++) {
        temp *= window[j];         // Introduce loop-carried dependency (temp depends on previous iteration)
        in[j] = in[j] * temp;      // WAW and RAW dependencies introduced via temp
    }
}
