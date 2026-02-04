#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int *restrict ip;
extern real_t alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 6400; i++) {
        int base = i * 5;
        a[base] += alpha * b[ip[31999 - i]];
        a[base + 1] += alpha * b[ip[31998 - i]];
        a[base + 2] += alpha * b[ip[31997 - i]];
        a[base + 3] += alpha * b[ip[31996 - i]];
        a[base + 4] += alpha * b[ip[31995 - i]];
    }
}
}
