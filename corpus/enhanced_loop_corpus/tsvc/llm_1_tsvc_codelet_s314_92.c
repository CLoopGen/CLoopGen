#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t local_x;
    for (int nl = 0; nl < 100000 * 5; nl++) {
        for (int ib = 0; ib < 32000; ib += 64) {
            local_x = a[ib];
            for (int i = ib; i < ib + 64 && i < 32000; i++) {
                if (a[i] > local_x) {
                    local_x = a[i];
                }
            }
            if (ib == 0 || a[ib] > x) {
                x = local_x;
            }
        }
    }
}
