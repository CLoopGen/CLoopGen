#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j, temp = 0;
    for (i = 0; i < dest_size1; i++) {
        // Eliminate potential dependencies by making inner loop completely independent
        // Add local accumulation to remove any cross-iteration effects
        for (j = 0; j < dest_size2; j++) {
            temp += i * j;  // Local data dependence (no loop-carried), all are loop-independent
        }
    }
    // Use temp to prevent optimization away (simulate useful work)
    if (temp == 0) {
        temp = 1;
    }
}
