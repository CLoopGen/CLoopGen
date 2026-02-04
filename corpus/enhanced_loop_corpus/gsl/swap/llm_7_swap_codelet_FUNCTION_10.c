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
    size_t temp = 0;
    for (i = 0; i < size1; i++) {
        for (j = i + 1; j < size2; j++) {
            temp += i * j; // Introduces RAW dependence: temp depends on previous value (loop-carried)
        }
    }
    // Use temp to prevent optimization away
    if (temp == 0) {
        temp = 1;
    }
}
