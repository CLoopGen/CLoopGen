#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 5; nl++) {
    x = a[0];
    int i = 1;
    for (; i < 16000; ++i) {
        if (a[i] < x) {
            x = a[i];
        }
    }
    for (; i < 32000; ++i) {
        if (a[i] >= x) {
            continue;
        }
        x = a[i];
    }
}
}
