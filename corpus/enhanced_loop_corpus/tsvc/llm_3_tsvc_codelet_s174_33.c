#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int M;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * 100000; nl++) {
    for (int i = 0; i < M; i++) {
        int idx = (i * 3) % M; // Strided access with modulo to stay within bounds
        a[idx + M] = a[idx] + b[idx];
    }
}
}
