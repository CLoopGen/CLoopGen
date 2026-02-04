#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    for (int i = 0; i < 32000 / 4; i++) {
        int idx_b = 2 * i;
        int idx_c = 2 * i + 1;
        int idx_d = (i * 3) % (32000 / 2);  // Strided access with modulo to stay in bounds
        int idx_e = (i * 5) % (32000 / 2);
        int j = 4 * i;
        a[j]     = b[idx_b] + c[idx_c] * d[idx_d];
        a[j+1]   = b[idx_b] + d[idx_d] * e[idx_e];
        a[j+2]   = b[idx_c] + c[idx_b] * d[idx_e];
        a[j+3]   = b[idx_c] + d[idx_c] * e[idx_d];
    }
}
}
