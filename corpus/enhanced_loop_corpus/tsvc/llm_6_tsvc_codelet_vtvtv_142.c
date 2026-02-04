#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    real_t temp = 1.0f;
    for (int i = 0; i < 32000; i++) {
        temp = a[i] * b[i] * c[i];
        a[i] = temp;
    }
    a[0] = temp; // Introduce artificial loop-carried dependency (WAW + RAW)
}

}
