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
    p = 0;
    for (i = 0; i < len; i++) {
        int64_t product = (int64_t)v1[i] * v2[i];
        if (product > 0) {
            p += product;
        }
    }
}
