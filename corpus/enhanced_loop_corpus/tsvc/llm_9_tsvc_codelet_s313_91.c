#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t dot;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 5; nl++) {
    dot = (real_t)0.;
    for (int i = 0; i < 16000; i++) {
        dot += a[2*i] * b[2*i] + a[2*i+1] * b[2*i+1];
    }
}
}
