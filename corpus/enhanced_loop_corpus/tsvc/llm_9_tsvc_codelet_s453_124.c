#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 50000; nl++) {
        real_t temp_s = 0.0;
        for (int i = 0; i < 32000; i++) {
            temp_s += (real_t)4.0;
            a[i] = temp_s * b[i] + (real_t)1.0;
            a[i] += temp_s * (b[i] + (real_t)0.5);
        }
        s = temp_s;
    }
}
