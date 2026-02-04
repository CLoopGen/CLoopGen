#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 10; nl++) {
    for (int j = 0; j < 32000 - 5; j += 5) {
        for (int k = 0; k < 5; k++) {
            a[j + k] = a[j + k + 1] * a[j + k];
        }
    }
}
}
