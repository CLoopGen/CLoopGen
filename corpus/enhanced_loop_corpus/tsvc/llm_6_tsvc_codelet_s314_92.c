#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t temp_x = x;
    for (int nl = 0; nl < 100000 * 5; nl++) {
        temp_x = a[0];
        for (int i = 1; i < 32000; i += 2) {
            real_t val1 = a[i];
            real_t val2 = a[i + 1];
            if (val1 > temp_x) {
                temp_x = val1;
            }
            if (val2 > temp_x) {
                temp_x = val2;
            }
        }
        x = temp_x;
    }
}
