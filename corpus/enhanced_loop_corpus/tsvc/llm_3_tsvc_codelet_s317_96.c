#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 5 * 100000; nl++) {
    q = (real_t)1.;
    int indices[8] = {0, 4000, 1000, 3000, 2000, 500, 2500, 1500};
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 32000 / (2 * 8); i++) {
            q *= (real_t)0.98999999999999999;
        }
        q *= (real_t)(0.98999999999999999 + (indices[j] % 10) * 1e-5);
    }
}
}
