#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int int32;

int32 *val;
int32 len;
int32 i;
int32 bi;

void init_vars() {
    len = 65536; // Adjust size for ~0.01 sec runtime
    val = (int32*)malloc(len * sizeof(int32));
    if (!val) {
        len = 0;
        return;
    }
    for (int j = 0; j < len; j++) {
        val[j] = rand();
    }
    bi = 0;
    i = 0;
}