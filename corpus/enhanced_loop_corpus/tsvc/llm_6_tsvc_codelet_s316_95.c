#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t temp = x;
    for (int nl = 0; nl < 100000 * 5; nl++) {
        temp = a[0];
        for (int i = 1; i < 32000; ++i) {
            if (a[i] < temp) {
                temp = a[i];
            }
        }
        x = temp;
    }
}
