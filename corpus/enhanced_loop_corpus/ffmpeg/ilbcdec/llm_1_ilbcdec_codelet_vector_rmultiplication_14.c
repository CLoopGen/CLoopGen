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
    if (length > 0) {
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < length; j++) {
                out[j] = (in[j] * win[-j]) >> shift;
            }
        }
    }
}
