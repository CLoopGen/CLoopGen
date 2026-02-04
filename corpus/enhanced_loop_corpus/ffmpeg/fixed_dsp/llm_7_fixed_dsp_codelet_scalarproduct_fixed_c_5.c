#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *v1;
extern  int *v2;
extern int len;
extern int64_t p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t local_p = p;
    for (i = 0; i < len; i += 2) {
        int64_t prod1 = (int64_t)v1[i] * v2[i];
        int64_t prod2 = (i + 1 < len) ? (int64_t)v1[i + 1] * v2[i + 1] : 0;
        local_p += prod1 + prod2;
    }
    p = local_p;
}
