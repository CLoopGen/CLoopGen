#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int inc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int nj = 0; nj < 10; nj++) {
        for (int ni = 0; ni < 3200; ni++) {
            int i = ni + nj * 3200;
            a[i * inc] += b[i];
        }
    }
}
}
