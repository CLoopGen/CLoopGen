#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    sum = 0.;
    for (int i = 0; i < 32000; i += 2) {
        sum += a[i] * b[ip[i]] + a[i+1] * b[ip[i+1]];
    }
}
}
