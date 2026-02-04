#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *vector;
extern int i;
extern int cb_gain;
extern int cb_shift;
extern int cb_sign;
extern int cb_pos;
extern int offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 1; ++depth1) {
        for (i = 0; i < 8; i += 2) {
            offset = ((cb_pos & 7) << 3) + cb_shift + i;
            vector[offset] = (cb_sign & 1) ? cb_gain : -cb_gain;
            cb_pos >>= 3;
            cb_sign >>= 1;
        }
    }
}
