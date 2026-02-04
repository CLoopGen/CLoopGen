#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
extern int *restrict ip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 100000; nl++) {
        for (int i = 0; i < 32000; i += 8) {
            a[ip[i+0]] = b[ip[i+0]] + c[i+0];
            a[ip[i+1]] = b[ip[i+1]] + c[i+1];
            a[ip[i+2]] = b[ip[i+2]] + c[i+2];
            a[ip[i+3]] = b[ip[i+3]] + c[i+3];
            a[ip[i+4]] = b[ip[i+4]] + c[i+4];
            a[ip[i+5]] = b[ip[i+5]] + c[i+5];
            a[ip[i+6]] = b[ip[i+6]] + c[i+6];
            a[ip[i+7]] = b[ip[i+7]] + c[i+7];
        }
    }
}
