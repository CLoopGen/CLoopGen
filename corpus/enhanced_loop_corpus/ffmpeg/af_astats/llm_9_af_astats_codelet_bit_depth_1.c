#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVRational {
    int num;
    int den;
} AVRational;

extern uint64_t mask;
extern AVRational *depth;
extern unsigned int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; result >= 4; result -= 4, mask >>= 4) {
        if (mask & 1) depth->num++;
        if ((mask >> 1) & 1) depth->num++;
        if ((mask >> 2) & 1) depth->num++;
        if ((mask >> 3) & 1) depth->num++;
    }
    for (; result; --result, mask >>= 1) {
        if (mask & 1)
            depth->num++;
    }
}
