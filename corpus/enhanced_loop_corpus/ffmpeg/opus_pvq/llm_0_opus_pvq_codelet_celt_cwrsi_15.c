#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t K;
extern uint32_t i;
extern uint32_t p;
extern  uint32_t *row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint32_t temp = row[K]; temp > i; ) {
        for (p = row[K]; p > i; p = row[K])
            K--;
        temp = row[K];
    }
}
