#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int val;
extern int len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        dst[0] = val;
        for (n = 1; n < len; n++) {
            dst[n] = val;
        }
    }
}
