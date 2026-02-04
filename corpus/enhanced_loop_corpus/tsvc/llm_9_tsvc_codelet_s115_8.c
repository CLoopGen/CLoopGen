#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2000 * (100000 / 256); nl++) {
    for (int j = 0; j < 256; j++) {
        real_t aj = a[j];
        for (int i = j + 1; i < 256; i += 4) {
            a[i] -= aa[j][i] * aj;
            if (i + 1 < 256) a[i + 1] -= aa[j][i + 1] * aj;
            if (i + 2 < 256) a[i + 2] -= aa[j][i + 2] * aj;
            if (i + 3 < 256) a[i + 3] -= aa[j][i + 3] * aj;
        }
    }
}
}
