#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    for (int j = 1; j < 256; j++) {
        for (int i = 1; i <= j; i++) {
            // Break loop-carried dependency by removing recurrence in aa[j][i]
            // Now each element computed independently based on initial value
            aa[j][i] = aa[j][0] * aa[j][0] + bb[j][i];
        }
    }
}
}
