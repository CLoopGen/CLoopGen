#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern int *restrict ip;
extern int n1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    real_t temp_a;
    for (int i = n1 - 1; i < 32000; i++) {
        k = ip[i];
        int index_c = 32000 - k + 1 - 2;
        temp_a = b[i] + c[index_c] * d[i];  // Break WAW dependency on a[i] across iterations
        a[i] = temp_a;                     // Store after computation (same effect, but separates use from def)
        k += 5;                            // Remove potential WAR by making k local to iteration
    }
}
}
