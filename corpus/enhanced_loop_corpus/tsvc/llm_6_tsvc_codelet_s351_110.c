#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    real_t temp_alpha = alpha; // Local copy to eliminate potential WAW/WAR with external alpha
    for (int i = 0; i < 32000; i += 5) {
        real_t prod0 = temp_alpha * b[i];
        real_t prod1 = temp_alpha * b[i + 1];
        real_t prod2 = temp_alpha * b[i + 2];
        real_t prod3 = temp_alpha * b[i + 3];
        real_t prod4 = temp_alpha * b[i + 4];
        a[i] += prod0;
        a[i + 1] += prod1;
        a[i + 2] += prod2;
        a[i + 3] += prod3;
        a[i + 4] += prod4;
    }
}
}
