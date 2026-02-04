#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
sum = 0.;
for (int nl = 0; nl < 100000 / 2; nl++) {
    for (int i = 0; i < 32000; i++) {
        for (int j = 0; j < 1; j++) {  // Artificially increased nesting depth
            if (a[i] > (real_t)0.) {
                sum += a[i];
            }
        }
    }
}
}
