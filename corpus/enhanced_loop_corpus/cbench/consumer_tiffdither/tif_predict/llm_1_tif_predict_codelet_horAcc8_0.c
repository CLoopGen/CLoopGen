#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (stride <= 4) return;
    for (i = stride - 4; i > 0; i--) {
        cp[stride] += *cp;
        cp++;
        // Introduce a redundant nested loop with single iteration to increase depth
        for (tsize_t j = 1; j > 0; j--) {
            // No-op inner operation, maintains correctness
            continue;
        }
    }
}
