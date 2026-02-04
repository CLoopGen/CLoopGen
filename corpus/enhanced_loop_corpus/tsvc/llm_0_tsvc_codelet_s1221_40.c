#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 4; i < 8000; i++) {
        b[i] = b[i - 4] + a[i];
    }
    for (int i = 8000; i < 16000; i++) {
        b[i] = b[i - 4] + a[i];
    }
    for (int i = 16000; i < 24000; i++) {
        b[i] = b[i - 4] + a[i];
    }
    for (int i = 24000; i < 32000; i++) {
        b[i] = b[i - 4] + a[i];
    }
}
}
