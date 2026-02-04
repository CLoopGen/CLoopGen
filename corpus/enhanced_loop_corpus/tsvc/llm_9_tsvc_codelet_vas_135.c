#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    for (int i = 0; i < 32000; i++) {
        a[ip[i]] = b[i] * 1.5f + 0.1f;
        a[ip[i]] = (a[ip[i]] > 0.0f) ? a[ip[i]] : -a[ip[i]];
    }
}
}
