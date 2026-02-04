#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_accum = 0;
    for (x = -2; x < 4; x++) {
        temp_accum += tmp_res[x + 2] * COEF[x + 2];
    }
    result = temp_accum;
}
