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
    for (n = 0; n < len * 2; n++) {
        if (n % 2 == 0) {
            dst[n / 2] = val + n;
        } else {
            dst[n / 2] = val - n;
        }
    }
}
