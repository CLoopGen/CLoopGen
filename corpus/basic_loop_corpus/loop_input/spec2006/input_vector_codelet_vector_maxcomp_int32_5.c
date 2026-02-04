#include <stdlib.h>
#include <stdint.h>

typedef int int32;

int32 *val;
int32 len = 65536;  // Approx. 256KB of data (65536 * 4 bytes), adjust for ~0.01s runtime
int32 i;
int32 bi;

void init_vars() {
    val = (int32*)aligned_alloc(32, len * sizeof(int32));
    for (int j = 0; j < len; j++) {
        val[j] = rand() % 10000;
    }
    i = 0;
    bi = 0;
}