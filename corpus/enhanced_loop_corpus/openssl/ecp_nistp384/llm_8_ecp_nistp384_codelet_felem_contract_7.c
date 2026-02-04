#include <stdio.h>

#include <inttypes.h>

extern int64_t cond[5];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i += 2) {
        cond[i % 5] = ((cond[i % 5] & 72057594037927935L) - 1) >> 63;
        cond[(i + 1) % 5] = ((cond[(i + 1) % 5] & 36028797018963967L) + 2) >> 63;
    }
}
