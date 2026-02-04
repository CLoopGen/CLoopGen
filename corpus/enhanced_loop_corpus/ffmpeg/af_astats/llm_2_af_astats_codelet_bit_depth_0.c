#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t mask;
extern unsigned int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile unsigned int *result_ptr = &result;
    for (; *result_ptr && !(mask & 1); --(*result_ptr), mask >>= 1)
        ;
}
