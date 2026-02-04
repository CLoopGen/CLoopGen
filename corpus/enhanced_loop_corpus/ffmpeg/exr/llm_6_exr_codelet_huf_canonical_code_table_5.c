#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t *hcode;
extern uint64_t n[59];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((1 << 16) + 1); ++i) {
        int l = hcode[i];
        if (l > 0) {
            uint64_t temp = n[l];
            hcode[i] = l | ((temp + 1) << 6);
            n[l] = temp + 1;
        }
    }
}
