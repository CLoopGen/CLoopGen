#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 100000 * 2; nl++) {
        real_t local_s = (real_t)2.0 * 32000; // Final value of s after loop
        for (int i = 31999; i >= 0; i--) {
            a[i] = local_s * b[i];
            local_s -= (real_t)2.0;
        }
        s = (real_t)2.0 * 32000;
    }
}
