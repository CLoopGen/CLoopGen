#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    int i = 0;
    for (; i < 32000 - 7; i += 8) {
        a[ip[i]]   = b[i];
        a[ip[i+1]] = b[i+1];
        a[ip[i+2]] = b[i+2];
        a[ip[i+3]] = b[i+3];
        a[ip[i+4]] = b[i+4];
        a[ip[i+5]] = b[i+5];
        a[ip[i+6]] = b[i+6];
        a[ip[i+7]] = b[i+7];
    }
    for (; i < 32000; i++) {
        a[ip[i]] = b[i];
    }
}
}
