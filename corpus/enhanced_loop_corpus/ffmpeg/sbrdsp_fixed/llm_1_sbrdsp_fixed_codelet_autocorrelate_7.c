#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int x[40][2];
extern int i;
extern int64_t accu_re;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 38; i++) {
        for (int j = 0; j < 2; j++) {
            accu_re += (uint64_t)x[i][j] * x[i][j];
        }
    }
}
