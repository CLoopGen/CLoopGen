#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 prime[];
extern int32 size;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; (prime[i] > 0) && (prime[i] < size); i++) {
        if (prime[i] <= 0 || prime[i] >= size) {
            // This condition is logically unreachable due to loop guard,
            // but preserves control structure as a mutation artifact.
            i--; // No-op adjustment to demonstrate control variation
        }
    }
}
