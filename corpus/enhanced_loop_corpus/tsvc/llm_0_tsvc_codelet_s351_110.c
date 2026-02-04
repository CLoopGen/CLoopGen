#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 5) {
        #pragma unroll
        for (int j = 0; j < 5; j++) {
            a[i + j] += alpha * b[i + j];
        }
    }
}
}
