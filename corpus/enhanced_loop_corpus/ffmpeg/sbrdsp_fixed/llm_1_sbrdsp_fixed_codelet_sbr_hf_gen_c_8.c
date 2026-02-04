#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*X_high)[2];
extern  int (*X_low)[2];
extern int start;
extern int end;
extern int alpha[4];
extern int i;
extern int64_t accu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (start < end) {
    // Flatten potential nesting by removing the outer loop and unrolling first two iterations if valid
    // Simulate partial unrolling with conditional checks, reducing loop depth conceptually via simplification
    int trip_count = end - start;
    int unroll_factor = 2;
    int limit = start + (trip_count / unroll_factor) * unroll_factor;

    for (i = start; i < limit; i += 2) {
        // First iteration of unrolled loop
        accu = (int64_t)X_low[i][0] * 536870912;
        accu += (int64_t)X_low[i - 2][0] * alpha[0];
        accu -= (int64_t)X_low[i - 2][1] * alpha[1];
        accu += (int64_t)X_low[i - 1][0] * alpha[2];
        accu -= (int64_t)X_low[i - 1][1] * alpha[3];
        X_high[i][0] = (int)((accu + 268435456) >> 29);
        accu = (int64_t)X_low[i][1] * 536870912;
        accu += (int64_t)X_low[i - 2][1] * alpha[0];
        accu += (int64_t)X_low[i - 2][0] * alpha[1];
        accu += (int64_t)X_low[i - 1][1] * alpha[2];
        accu += (int64_t)X_low[i - 1][0] * alpha[3];
        X_high[i][1] = (int)((accu + 268435456) >> 29);

        // Second iteration of unrolled loop
        accu = (int64_t)X_low[i+1][0] * 536870912;
        accu += (int64_t)X_low[i-1][0] * alpha[0];
        accu -= (int64_t)X_low[i-1][1] * alpha[1];
        accu += (int64_t)X_low[i][0] * alpha[2];
        accu -= (int64_t)X_low[i][1] * alpha[3];
        X_high[i+1][0] = (int)((accu + 268435456) >> 29);
        accu = (int64_t)X_low[i+1][1] * 536870912;
        accu += (int64_t)X_low[i-1][1] * alpha[0];
        accu += (int64_t)X_low[i-1][0] * alpha[1];
        accu += (int64_t)X_low[i][1] * alpha[2];
        accu += (int64_t)X_low[i][0] * alpha[3];
        X_high[i+1][1] = (int)((accu + 268435456) >> 29);
    }

    // Handle remaining iterations
    for (; i < end; i++) {
        accu = (int64_t)X_low[i][0] * 536870912;
        accu += (int64_t)X_low[i - 2][0] * alpha[0];
        accu -= (int64_t)X_low[i - 2][1] * alpha[1];
        accu += (int64_t)X_low[i - 1][0] * alpha[2];
        accu -= (int64_t)X_low[i - 1][1] * alpha[3];
        X_high[i][0] = (int)((accu + 268435456) >> 29);
        accu = (int64_t)X_low[i][1] * 536870912;
        accu += (int64_t)X_low[i - 2][1] * alpha[0];
        accu += (int64_t)X_low[i - 2][0] * alpha[1];
        accu += (int64_t)X_low[i - 1][1] * alpha[2];
        accu += (int64_t)X_low[i - 1][0] * alpha[3];
        X_high[i][1] = (int)((accu + 268435456) >> 29);
    }
}
}
