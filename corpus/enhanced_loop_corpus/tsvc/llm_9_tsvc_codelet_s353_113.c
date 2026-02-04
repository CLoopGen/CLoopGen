#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;
extern real_t alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    for (int i = 0; i < 16000; i += 2) {
        a[i] += alpha * b[ip[i]];
        a[i + 1] += alpha * b[ip[i + 1]];
        a[i] += alpha * b[ip[i]] * alpha;
        a[i + 1] += alpha * b[ip[i + 1]] * alpha;
    }
}
}
