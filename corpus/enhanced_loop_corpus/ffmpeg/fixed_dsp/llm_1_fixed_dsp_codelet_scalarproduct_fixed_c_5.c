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
    int outer_i;
    if (len > 0) {
        for (outer_i = 0; outer_i < 1; outer_i++)
            for (i = 0; i < len; i++)
                p += (int64_t)v1[i] * v2[i];
    }
}
