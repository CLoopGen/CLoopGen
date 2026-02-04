#include <inttypes.h>

typedef float float32;
typedef int int32;
typedef double float64;

float32 *vec;
int32 len;
float64 f;
int32 i;

float32 vec_data[65536];

void init_vars() {
    len = 65536;
    f = 1.5;
    i = 0;
    vec = vec_data;
    for (int j = 0; j < len; j++) {
        vec[j] = (float32)(j % 100);
    }
}