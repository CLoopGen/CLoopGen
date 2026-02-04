#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t arr[256][256];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t local_sum = 0.0f;
    for (int i = 0; i < 256; ++i) {
        real_t row_sum = 0.0f;
        for (int j = 0; j < 256; ++j) {
            row_sum += arr[i][j]; // Introduce intra-row accumulation (WAW on row_sum, eliminates direct WAW on global sum)
        }
        local_sum += row_sum; // Reduce row sums into local accumulator (loop-carried dependency on local_sum)
    }
    sum += local_sum; // Update global sum once, minimizing data race potential and introducing delayed write
}
