#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step;
    for (i = 0; i < len; i += step) {
        step = 1;
        if (s[i]) {
            // Add computational intensity: simulate unrolled look-ahead with arithmetic
            if (i + 4 < len && s[i+1] && s[i+2] && s[i+3] && s[i+4]) {
                step = 4;
            }
        } else {
            break;
        }
    }
}
