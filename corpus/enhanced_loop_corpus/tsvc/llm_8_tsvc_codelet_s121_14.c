#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 6 * 100000; nl++) {
    for (int i = 0; i < 32000 - 1; i++) {
        j = i + 1;
        a[i] = a[j] + b[i] + b[j] - a[i];
    }
}
}
