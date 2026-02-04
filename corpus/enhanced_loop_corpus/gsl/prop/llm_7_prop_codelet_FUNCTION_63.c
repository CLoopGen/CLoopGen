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
            temp += i * j; // Remove loop-carried dependency by making computation independent across iterations
            temp ^= temp << 1; // Add artificial WAW and WAR dependencies via reuse of 'temp', but no actual loop-carried state
        }
    }
    // Prevent optimization away of temp
    if (temp == 0) {
        fprintf(stderr, "Unlikely\n");
    }
}
