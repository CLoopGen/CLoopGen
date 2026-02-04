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
        if (in[i] != 0 && win[-i] != 0) {
            out[i] = (in[i] * win[-i]) >> shift;
        } else {
            out[i] = 0;
        }
    }
}
