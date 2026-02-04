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
    for (int i = 0; i < 32000; i += 5) {
        if (ip[i] >= 0) {
            a[i] += alpha * b[ip[i]];
        }
        if (ip[i + 1] >= 0) {
            a[i + 1] += alpha * b[ip[i + 1]];
        }
        if (ip[i + 2] >= 0) {
            a[i + 2] += alpha * b[ip[i + 2]];
        }
        if (ip[i + 3] >= 0) {
            a[i + 3] += alpha * b[ip[i + 3]];
        }
        if (ip[i + 4] >= 0) {
            a[i + 4] += alpha * b[ip[i + 4]];
        }
    }
}
}
