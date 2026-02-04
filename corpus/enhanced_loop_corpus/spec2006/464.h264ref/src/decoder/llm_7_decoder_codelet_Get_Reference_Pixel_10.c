#include <stdio.h>

#include <inttypes.h>

extern int y;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_result[6];
    for (y = -2; y < 4; y++) {
        local_result[y + 2] = tmp_res[y + 2] * COEF[y + 2];
    }
    for (y = 0; y < 6; y++) {
        result += local_result[y];
    }
}
