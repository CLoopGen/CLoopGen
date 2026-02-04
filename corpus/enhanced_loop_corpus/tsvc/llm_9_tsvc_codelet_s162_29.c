#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    if (k > 0) {
        for (int i = 0; i < 16000; i++) {
            real_t temp1 = b[i] * c[i];
            real_t temp2 = b[i + 16000] * c[i + 16000];
            a[i] = a[i + k] + temp1;
            a[i + 16000] = a[i + 16000 + k] + temp2;
        }
    }
}
}
