#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 6 * 100000; nl += 2) {
    for (int i = 32000 - 3; i >= 0; i--) {
        a[i + 2] = a[i] + b[i];
        a[i + 1] = a[i] + b[i+1];
    }
}
}
