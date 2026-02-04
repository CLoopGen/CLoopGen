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
    for (n = 0; n < len; n += 2) {
        dst[n] = val;
        if (n + 1 < len) {
            dst[n + 1] = val ^ 0xFFFF;
        }
    }
}
