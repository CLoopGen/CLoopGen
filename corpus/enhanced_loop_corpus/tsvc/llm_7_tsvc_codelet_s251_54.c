#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    real_t local_s = s;
    for (int i = 0; i < 32000; i += 4) {
        local_s = b[i] + c[i] * d[i];
        a[i] = local_s * local_s;
        local_s = b[i+1] + c[i+1] * d[i+1];
        a[i+1] = local_s * local_s;
        local_s = b[i+2] + c[i+2] * d[i+2];
        a[i+2] = local_s * local_s;
        local_s = b[i+3] + c[i+3] * d[i+3];
        a[i+3] = local_s * local_s;
    }
    s = local_s;
}
}
