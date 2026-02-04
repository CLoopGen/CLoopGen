#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile uint64_t temp;
    for (i = 0; i < size1; i++) {
        temp = i * 31; // WAW: temp is overwritten each iteration, no loop-carried dep
        for (j = 0; j < size2; j++) {
            temp ^= j; // WAR-like pattern via volatile use; no true loop-carried dependency
            temp += j * 7;
        }
        // Use temp to prevent elimination
        asm volatile("" : "+r"(temp));
    }
}
