#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp = 0;
    for (count = 0; fmts[count] != -1 && count < 1000; count++) {
        temp += fmts[count] * fmts[count] + count;
    }
    temp = temp * temp;
}
