#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int n1;
extern int n3;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    int local_j = 1;
    int local_k = 0;
    for (int i = n1 - 1; i < 32000; i += n3) {
        local_k += local_j;
        a[i] += b[32000 - local_k];
    }
}
}
