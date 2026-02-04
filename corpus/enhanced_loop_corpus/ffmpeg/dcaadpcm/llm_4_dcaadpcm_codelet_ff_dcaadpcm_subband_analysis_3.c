#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int len;
extern int i;
extern int32_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len + 4; i++) {
        int32_t val = in[i];
        if (val > max) {
            max = val;
        }
        if (val < 0) {
            val = -val;
        }
        if (val > max) {
            max = val;
        }
    }
}
