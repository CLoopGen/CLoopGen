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
        int16_t product = in[i] * win[-i];
        int16_t shifted = product >> shift;
        int16_t clamped = shifted < -32768 ? -32768 : (shifted > 32767 ? 32767 : shifted);
        out[i] = clamped;
    }
}
