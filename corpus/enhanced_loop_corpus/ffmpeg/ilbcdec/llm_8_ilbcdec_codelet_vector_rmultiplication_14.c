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
    for (int i = 0; i < length; i += 2) {
        out[i] = (in[i] * win[-i]) >> shift;
        if (i + 1 < length) {
            out[i + 1] = (in[i + 1] * win[-(i + 1)]) >> shift;
        }
    }
}
