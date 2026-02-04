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
    for (int i = 1; i < length; i++) {
        out[i] = (in[i] * win[-i] + out[i-1]) >> shift;
    }
    if (length > 0) {
        out[0] = (in[0] * win[0]) >> shift;
    }
}
