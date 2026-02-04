#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t prod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * 100000; nl++) {
    prod = (real_t)1.;
    for (int i = 0; i < 32000; i += 4) {
        prod *= a[i];
        if (i + 1 < 32000) prod *= a[i + 1];
        if (i + 2 < 32000) prod *= a[i + 2];
        if (i + 3 < 32000) prod *= a[i + 3];
    }
}
}
