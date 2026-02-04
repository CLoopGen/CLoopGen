#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in;
extern  int16_t *win;
extern int length;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < length; i++) {
        int16_t product1 = in[i] * win[i];
        int16_t product2 = (i > 0) ? in[i] * win[i-1] : in[i] * win[i];
        int16_t combined = (product1 + product2) >> 1;
        out[i] = combined >> shift;
    }
}
