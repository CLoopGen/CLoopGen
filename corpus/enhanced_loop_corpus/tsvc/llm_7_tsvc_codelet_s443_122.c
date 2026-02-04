#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    #pragma unroll 4
    for (int i = 0; i < 32000 - 3; i += 4) {
        // Eliminate control flow and unroll to expose parallelism
        // Remove branching by using conditional computation (no goto)
        // This removes data-dependent control flow, reducing WAR/WAW hazards

        // Process 4 elements per iteration with no data dependencies between them
        a[i]   += (d[i]   <= (real_t)0.) ? b[i]   * c[i]   : b[i]   * b[i];
        a[i+1] += (d[i+1] <= (real_t)0.) ? b[i+1] * c[i+1] : b[i+1] * b[i+1];
        a[i+2] += (d[i+2] <= (real_t)0.) ? b[i+2] * c[i+2] : b[i+2] * b[i+2];
        a[i+3] += (d[i+3] <= (real_t)0.) ? b[i+3] * c[i+3] : b[i+3] * b[i+3];
    }
    // Handle remainder
    for (int i = 32000 - (32000 % 4); i < 32000; i++) {
        a[i] += (d[i] <= (real_t)0.) ? b[i] * c[i] : b[i] * b[i];
    }
}
}
