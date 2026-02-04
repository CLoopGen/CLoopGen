#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real_t local_q = (real_t)1.;
for (int nl = 0; nl < 5 * 100000; nl++) {
    for (int i = 0; i < 32000 / 2; i++) {
        local_q = local_q * (real_t)0.98999999999999999 + (real_t)(nl % 100);
    }
}
q = local_q;
}
