#include <inttypes.h>

typedef float real_t;

real_t arr[256][256];
real_t sum;

void init_vars() {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            arr[i][j] = (real_t)(i + j);
        }
    }
    sum = 0.0f;
}