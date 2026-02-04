#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    real_t temp = a[0];
    for (int i = 1; i < 32000; i++) {
        real_t next_temp = temp * b[i];
        a[i] += next_temp;
        temp = a[i]; 
    }
}
}
