#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 100000 * 5; nl++) {
        x = a[0];
        for (int i = 1; i < 32000; i += 8) {
            real_t min_val = x;
            for (int j = 0; j < 8 && (i + j) < 32000; ++j) {
                if (a[i + j] < min_val) {
                    min_val = a[i + j];
                }
            }
            if (min_val < x) {
                x = min_val;
            }
        }
    }
}
