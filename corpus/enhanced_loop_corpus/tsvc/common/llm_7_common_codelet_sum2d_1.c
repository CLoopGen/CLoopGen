#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t arr[256][256];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0f; // Eliminate any prior value dependency by resetting sum (introduces WAW if called multiple times)
    for (int j = 0; j < 256; ++j) {
        for (int i = 0; i < 256; ++i) {
            sum += arr[i][j]; // Transposed loop order introduces different cache access pattern
                              // and creates loop-carried RAW/WAW dependency on 'sum' with stride-256 access in original layout
        }
    }
}
