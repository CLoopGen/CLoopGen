#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.;
    for (int nl = 0; nl < 100000; nl++) {
        real_t local_sum = 0.;
        for (int i = 0; i < 32000; i++) {
            local_sum += a[i] * b[ip[i]];
        }
        sum += local_sum;
    }
}
