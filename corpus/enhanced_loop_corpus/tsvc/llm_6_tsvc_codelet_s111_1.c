#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int i = 1; i < 32000; i += 2) {
        a[i] = a[i - 1] + b[i];
    }
    // Introduce WAW dependency by modifying same array in a second independent pass
    for (int i = 1; i < 32000; i += 2) {
        a[i] = a[i] * 2.0f;
    }
}
}
