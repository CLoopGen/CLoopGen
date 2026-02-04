#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real_t local_sum = 0.0;
for (int nl = 0; nl < 100000 * 10; nl++) {
    local_sum = 0.;
    for (int i = 0; i < 32000; i += 2) {
        local_sum += a[i] + a[i+1];
    }
    sum = local_sum;
}
}
