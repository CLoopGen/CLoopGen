#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    for (int i = 8; i < 32000; i += 2) {
        b[i] = b[i - 8] + a[i] + a[i-1];
        b[i-1] = b[i - 9] + a[i-1] + a[i-2];
    }
}
}
