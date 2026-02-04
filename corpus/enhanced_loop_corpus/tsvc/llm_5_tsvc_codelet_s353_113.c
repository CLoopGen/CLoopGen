#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;
extern real_t alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000; i += 5) {
        if (i % 100 == 0) continue;
        a[i] += alpha * b[ip[i]];
        a[i + 1] += alpha * b[ip[i + 1]];
        a[i + 2] += alpha * b[ip[i + 2]];
        a[i + 3] += alpha * b[ip[i + 3]];
        a[i + 4] += alpha * b[ip[i + 4]];
    }
}
}
