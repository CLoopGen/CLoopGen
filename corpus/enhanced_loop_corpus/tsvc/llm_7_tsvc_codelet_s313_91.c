#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t dot;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 5; nl++) {
    dot = (real_t)0.;
    for (int i = 1; i < 32000; i++) {
        dot += a[i-1] * b[i];  // Introduce RAW dependency: a[i-1] depends on previous iteration
    }
    dot += a[31999] * b[0];    // Break potential vectorization and create loop-carried dependence
}
}
