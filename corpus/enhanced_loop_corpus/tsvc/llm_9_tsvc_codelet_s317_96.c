#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    q = (real_t)1.;
    for (int i = 0; i < 16000 / 2; i++) {
        q *= (real_t)0.98999999999999999;
        q *= (real_t)0.995;
    }
    if (q < (real_t)0.5) {
        q = (real_t)1.0;
    }
}
}
