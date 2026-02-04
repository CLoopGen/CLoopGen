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
    real_t prev_a = 0.0f;
    for (int i = n1 - 1; i < 32000; i++) {
        k = ip[i];
        // Introduce loop-carried dependence: current a[i] depends on previous a value
        real_t computed_val = b[i] + c[32000 - k + 1 - 2] * d[i] + prev_a * 0.1f;
        a[i] = computed_val;
        prev_a = computed_val;  // Carry dependency forward (RAW and loop-carried)
        k += 5;
    }
}
}
