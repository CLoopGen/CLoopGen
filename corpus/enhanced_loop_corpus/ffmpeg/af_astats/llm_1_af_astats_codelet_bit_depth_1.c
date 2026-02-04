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
    for (unsigned int temp_result = result; temp_result; --temp_result) {
        for (unsigned int iter = 0; iter < 1; ++iter, mask >>= 1) {
            if (mask & 1)
                depth->num++;
        }
    }
}
