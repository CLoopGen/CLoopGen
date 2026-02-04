#include <stdio.h>

#include <inttypes.h>

extern int64_t cond[5];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp[5];
    for (i = 0; i < 5; i++) {
        temp[i] = (cond[i] & 72057594037927935L) - 1;
    }
    for (i = 0; i < 5; i++) {
        cond[i] = temp[i] >> 63;
    }
}
