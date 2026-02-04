#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 5 * 100000; nl++) {
    q = (real_t)1.;
    for (int i = 0; i < 32000 / 2; i += 4) {
        q *= (real_t)0.98999999999999999;
        q *= (real_t)0.98999999999999999;
        q *= (real_t)0.98999999999999999;
        q *= (real_t)0.98999999999999999;
    }
}
}
