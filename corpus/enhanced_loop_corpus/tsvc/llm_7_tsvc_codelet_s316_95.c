#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 100000 * 5; nl++) {
        real_t local_x = a[0];
        for (int i = 1; i < 32000; ++i) {
            real_t prev_x = local_x;
            local_x = (a[i] < local_x) ? a[i] : local_x;
        }
        x = local_x;
    }
}
