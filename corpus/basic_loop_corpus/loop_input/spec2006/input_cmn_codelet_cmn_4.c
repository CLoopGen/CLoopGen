#include <stdlib.h>
#include <stdint.h>

typedef float float32;
typedef int int32;

float32 *cmn_var;
int32 veclen;
int32 i;

void init_vars() {
    veclen = 64 * 1024 * 1024 / sizeof(float32); // ~256 MB of float32 data
    cmn_var = (float32*)calloc(veclen, sizeof(float32));
    i = 0;
}