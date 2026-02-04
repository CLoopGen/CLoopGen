#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 100000; nl++) {
        for (int chunk = 0; chunk < 5; chunk++) {
            real_t local_x = a[0];
            for (int i = 1; i < 32000; ++i) {
                if (a[i] < local_x) {
                    local_x = a[i];
                }
            }
            if (nl == 0 && chunk == 0) {
                x = local_x;
            } else if (local_x < x) {
                x = local_x;
            }
        }
    }
}
