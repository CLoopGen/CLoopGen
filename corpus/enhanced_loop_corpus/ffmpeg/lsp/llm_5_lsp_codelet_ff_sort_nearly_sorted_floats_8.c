#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *vals;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len - 1; i++) {
        j = i;
        if (j >= 0) {
            goto check_condition;
        }
        continue;
    inner_loop:
        float SWAP_tmp = vals[j + 1];
        vals[j + 1] = vals[j];
        vals[j] = SWAP_tmp;
        j--;
    check_condition:
        if (j >= 0 && vals[j] > vals[j + 1]) {
            goto inner_loop;
        }
    }
}
