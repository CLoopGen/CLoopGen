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
for (int nl = 0; nl < 200000; nl++) {
    j = 2; // Modified increment step
    k = 1;
    for (int i = n1 - 1; i < 32000; i += n3 * 2) { // Strided loop with larger step, reducing trip count
        k += j;
        if (k < 32000) {
            a[i] += b[32000 - k];
        }
    }
}
}
