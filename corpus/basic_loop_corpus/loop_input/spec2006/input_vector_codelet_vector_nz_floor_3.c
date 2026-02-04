#include <inttypes.h>

typedef float float32;
typedef int int32;
typedef double float64;

float32 *vec;
int32 len;
float64 flr;
int32 i;

void init_vars() {
    len = 67108864; // Approximately 256MB of float32 data (67M elements)
    vec = (float32*)__builtin_malloc(len * sizeof(float32));
    flr = 1.5;
    i = 0;

    for (int32 idx = 0; idx < len; idx++) {
        vec[idx] = (idx % 3) ? 0.0f : 1.0f;
    }
}