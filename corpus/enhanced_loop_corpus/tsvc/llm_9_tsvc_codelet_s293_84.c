#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 16000; i++) {
        real_t temp = a[0] * 3.14159f;
        a[i] = temp + (temp * 0.5f);
        a[31999 - i] = temp - (temp * 0.25f);
    }
}
}
