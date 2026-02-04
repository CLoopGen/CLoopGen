#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    x = b[32000 - 1];
    for (int i = 0; i < 32000; i++) {
        a[i] = (b[i] + x) * (real_t)0.5;
        x = b[i];
    }
}

}
