#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * 100000; nl++) {
    for (int i = 0; i < 32000 / 2; i++) {
        if (i >= 16000) {
            a[i + k] = a[i] + b[i];
        } else {
            a[i + k] = a[i] + b[i];
        }
    }
}
}
