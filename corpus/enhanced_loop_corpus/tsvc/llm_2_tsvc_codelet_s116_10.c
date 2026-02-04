#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 10; nl++) {
    for (int i = 0; i < 32000 - 5; i += 5) {
        a[i + 4] = a[i + 5] * a[i + 4];
        a[i + 3] = a[i + 4] * a[i + 3];
        a[i + 2] = a[i + 3] * a[i + 2];
        a[i + 1] = a[i + 2] * a[i + 1];
        a[i] = a[i + 1] * a[i];
    }
}
}
