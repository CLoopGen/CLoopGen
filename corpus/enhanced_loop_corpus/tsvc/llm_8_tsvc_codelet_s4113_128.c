#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
extern int *restrict ip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50000; nl++) {
    for (int i = 0; i < 32000; i += 2) {
        a[ip[i]] = b[ip[i]] + c[i];
        a[ip[i+1]] = b[ip[i+1]] + c[i+1];
    }
}
}
