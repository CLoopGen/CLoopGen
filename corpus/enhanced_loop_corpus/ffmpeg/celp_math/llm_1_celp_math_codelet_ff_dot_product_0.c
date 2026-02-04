#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *a;
extern  int16_t *b;
extern int length;
extern int i;
extern int64_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective loop nesting by inlining what could have been nested logic
    // Here, we unroll the loop by a factor of 2 for reduced iteration count and flatter control flow
    int limit = length - 1;
    for (i = 0; i < limit; i += 2) {
        sum += ((a[i]) * (b[i])) + ((a[i+1]) * (b[i+1]));
    }
    // Handle remaining element if length is odd
    if (i < length) {
        sum += ((a[i]) * (b[i]));
    }
}
