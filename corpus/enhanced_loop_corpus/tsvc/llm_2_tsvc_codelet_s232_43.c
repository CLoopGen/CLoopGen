#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    for (int j = 1; j < 256; j++) {
        real_t *a_row = &aa[j][0];
        real_t *b_row = &bb[j][0];
        for (int i = 1; i <= j; i++) {
            a_row[i] = a_row[i - 1] * a_row[i - 1] + b_row[i];
        }
    }
}
}
