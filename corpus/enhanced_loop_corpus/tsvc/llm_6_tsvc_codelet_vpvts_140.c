#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    real_t temp_s = s;
    for (int i = 0; i < 32000; i += 4) {
        a[i]   += b[i]   * temp_s;
        a[i+1] += b[i+1] * temp_s;
        a[i+2] += b[i+2] * temp_s;
        a[i+3] += b[i+3] * temp_s;
    }
}
}
