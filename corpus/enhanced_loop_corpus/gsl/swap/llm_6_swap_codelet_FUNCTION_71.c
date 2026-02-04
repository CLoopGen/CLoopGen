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
    uint64_t temp = 0;
    for (i = 0; i < size1; i++) {
        temp += i * 2; // Introduce WAW dependency on temp, carried across iterations
        for (j = i + 1; j < size2; j++) {
            temp = temp + j - i; // RAW: uses i and j; WAR/WAW on temp with outer loop
        }
    }
}
