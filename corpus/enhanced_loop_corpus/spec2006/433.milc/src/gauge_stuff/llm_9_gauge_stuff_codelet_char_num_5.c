#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int bdig[6];
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified arithmetic,
    // but increased trip count via unrolling the original logic into two passes.
    // Simulate higher iteration count by processing each element twice.
    for (j = 2 * (length - 1); j >= 0; j--) {
        int index = j / 2;
        if (index < length - 1) {
            old = (j % 2 == 0) ? (old * 10 + bdig[index]) : (old + bdig[index]);
        }
    }
}
