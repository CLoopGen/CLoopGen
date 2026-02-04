#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int j = 0; j < 8000; j++) {
        for (int k = 0; k < 4; k++) {
            int i = (j << 2) + k;
            a[i] += b[ip[i]] * s;
        }
    }
}
}
