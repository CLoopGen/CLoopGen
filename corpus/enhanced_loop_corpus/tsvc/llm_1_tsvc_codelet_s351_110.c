#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8; nl++) {
    for (int nk = 0; nk < 100000; nk++) {
        for (int i = 0; i < 32000; i += 5) {
            a[i] += alpha * b[i];
            a[i + 1] += alpha * b[i + 1];
            a[i + 2] += alpha * b[i + 2];
            a[i + 3] += alpha * b[i + 3];
            a[i + 4] += alpha * b[i + 4];
        }
    }
}
}
