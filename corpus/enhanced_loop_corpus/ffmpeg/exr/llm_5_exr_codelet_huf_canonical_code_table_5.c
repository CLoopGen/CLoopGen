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
    if (l <= 0) continue;
    hcode[i] = l | (n[l]++ << 6);
}
}
