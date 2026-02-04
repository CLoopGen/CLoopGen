#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    int local_j = 0;
    for (int i = 0; i < 32000; i++) {
        real_t computed_val = d[i] * e[i];
        if (b[i] > (real_t)0.) {
            a[local_j] = b[i] + computed_val;
        } else {
            a[local_j] = c[i] + computed_val;
        }
        local_j++;
    }
    j = local_j - 1; // Update shared j after loop completes
}

}
