#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    real_t a0 = a[0]; // Introduce local copy to eliminate repeated reads (WAW and RAW reduction)
    for (int i = 1; i < 32000; i++) {
        a[i] = a0 + b[i]; // Remove loop-carried dependence on a[0]; only RAW on b[i]
    }
}
}
