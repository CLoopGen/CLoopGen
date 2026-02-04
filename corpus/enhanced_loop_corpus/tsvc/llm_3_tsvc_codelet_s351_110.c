#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    // Reverse consecutive access pattern: process array from end to start
    for (int i = 31999; i >= 0; i--) {
        a[i] += alpha * b[i];
    }
}
}
