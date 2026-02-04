#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int n1;
extern int n3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    #pragma omp simd // Enables vectorization by eliminating potential dependencies
    for (int i = n1 - 1; i < 32000; i += n3) {
        a[i] = b[i] + b[(i + 1) % 32000]; // Eliminates WAW and WAR hazards by using only reads and writing to distinct location; no loop-carried dependency
    }
}
}
