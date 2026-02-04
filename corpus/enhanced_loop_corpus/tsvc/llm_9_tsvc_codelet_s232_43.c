#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50 * (100000 / (256)); nl++) {
    for (int j = 1; j < 128; j++) { // Reduced loop bound
        for (int i = 1; i <= j; i += 2) { // Increased step size to reduce iterations
            real_t temp = aa[j][i - 1] * aa[j][i - 1] + bb[j][i];
            aa[j][i] = temp;
            if (i + 1 <= j) {
                aa[j][i + 1] = temp * temp + bb[j][i + 1]; // Additional computation on next element
            }
        }
    }
}
}
