#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int k = 0;
    for (j = 0; j < N; j++) {
        k += j; // Introduce loop-carried dependency: k accumulates value across iterations (RAW and recurrence)
    }
    // Prevent unused variable warning by potential side effect (though optimized out, maintains semantics)
    (void)k;
}
