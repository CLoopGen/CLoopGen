#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    sum = 0.;
    for (int i = 0; i < 32000; i += 4) {
        sum += a[i] * b[ip[i]];
        if (i+1 < 32000) sum += a[i+1] * b[ip[i+1]];
        if (i+2 < 32000) sum += a[i+2] * b[ip[i+2]];
        if (i+3 < 32000) sum += a[i+3] * b[ip[i+3]];
    }
}
}
