#include <stdio.h>
#include <stdlib.h>

#include <inttypes.h>

typedef float float32;
typedef int int32;

float32 *cmn_mean;
int32 veclen;
int32 i;

void init_vars() {
    veclen = 65536; // Approximately 256KB of data, sufficient for ~0.01 sec on modern CPU
    cmn_mean = (float32*)calloc(veclen, sizeof(float32));
    i = 0;
}