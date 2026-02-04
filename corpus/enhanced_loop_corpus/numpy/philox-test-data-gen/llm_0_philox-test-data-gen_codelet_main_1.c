#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 1000 / 4UL; i++) {
    for (j = 0; j < 4; j++) {
        // Add an additional inner loop to increase nesting depth
        for (int k = 0; k < 2; k++) {
            // Simulate some lightweight operation to maintain realism
            volatile int sink = k + i + j;
        }
    }
}
}
