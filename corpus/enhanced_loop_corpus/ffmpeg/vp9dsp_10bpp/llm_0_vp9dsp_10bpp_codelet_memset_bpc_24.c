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
    for (int i = 0; i < len; i += 16) {
        for (int j = 0; j < 16; j++) {
            if (i + j < len) {
                dst[i + j] = val;
            }
        }
    }
}
