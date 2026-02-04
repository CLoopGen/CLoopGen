#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 8) {
        // Strided access with step of 8, unrolled by 4 pairs
        if (i < 32000) a[i] += alpha * b[i];
        if (i + 2 < 32000) a[i + 2] += alpha * b[i + 2];
        if (i + 4 < 32000) a[i + 4] += alpha * b[i + 4];
        if (i + 6 < 32000) a[i + 6] += alpha * b[i + 6];
    }
}
}
