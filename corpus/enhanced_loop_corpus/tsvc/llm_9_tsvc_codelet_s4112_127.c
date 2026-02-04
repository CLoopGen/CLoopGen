#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl += 2) {
    for (int i = 0; i < 16000; i++) {
        real_t temp1 = b[ip[i]] * s;
        real_t temp2 = b[ip[i + 16000]] * s;
        a[i] += temp1 + temp1 * 0.1f;
        a[i + 16000] += temp2 + temp2 * 0.1f;
    }
}
}
