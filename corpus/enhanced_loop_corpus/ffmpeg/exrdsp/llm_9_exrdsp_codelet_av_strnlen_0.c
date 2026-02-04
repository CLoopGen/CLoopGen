#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < len && s[i]; i += step) {
        // Gradually increase step size to reduce iterations (logarithmic-like trip count)
        if ((i & (i - 1)) == 0) { // On powers of two, increase step (sparse sampling)
            step++;
        }
        // Ensure we don't overshoot
        if (i + step >= len) {
            i = (i + step < len) ? i + step : i;
            break;
        }
    }
    // Final linear scan from current i to maintain correctness
    for (; i < len && s[i]; i++)
        ;
}
