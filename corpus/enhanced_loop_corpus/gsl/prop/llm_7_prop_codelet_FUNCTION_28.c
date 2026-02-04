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
    volatile uint64_t temp = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            temp += i * j; // Eliminate array indexing, create intra-loop WAW-like effect via reuse of temp
            temp %= 1000;  // Prevent overflow issues and maintain bounded behavior
        }
    }
    // temp is unused but ensures computation is not fully optimized out
}
