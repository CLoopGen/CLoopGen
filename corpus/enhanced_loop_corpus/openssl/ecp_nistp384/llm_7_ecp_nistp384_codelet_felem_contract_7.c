#include <stdio.h>

#include <inttypes.h>

extern int64_t cond[5];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t prev = 0;
    for (i = 0; i < 5; i++) {
        int64_t current = (cond[i] & 72057594037927935L) - 1;
        cond[i] = (current + prev) >> 63;
        prev = current & ((1LL << 63) - 1);
    }
}
