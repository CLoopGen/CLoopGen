#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 5; nl++) {
    x = a[0];
    for (int i = 1; i < 32000; i += 4) {
        real_t val1 = a[i];
        real_t val2 = a[i+1];
        real_t val3 = a[i+2];
        real_t val4 = a[i+3];
        if (val1 > x) x = val1;
        if (val2 > x) x = val2;
        if (val3 > x) x = val3;
        if (val4 > x) x = val4;
    }
}
}
