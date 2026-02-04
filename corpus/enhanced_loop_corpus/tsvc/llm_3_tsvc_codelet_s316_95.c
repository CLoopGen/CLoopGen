#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 5; nl++) {
    x = a[0];
    for (int i = 16; i < 32000; i += 16) {
        for (int j = 0; j < 16; ++j) {
            int idx = i + j;
            if (idx < 32000 && a[idx] < x) {
                x = a[idx];
            }
        }
    }
}
}
