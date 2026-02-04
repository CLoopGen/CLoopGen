#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int nl = 0; nl < 100000 * 3; nl++) {
    for (int i = 32000 - 1; i >= 0; i--) {
        a[i] = b[i] + (real_t)1.;
    }
}

}
