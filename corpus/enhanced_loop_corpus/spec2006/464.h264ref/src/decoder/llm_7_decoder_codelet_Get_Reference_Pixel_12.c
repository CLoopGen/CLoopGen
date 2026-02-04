#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_result[6];
    for (x = -2; x < 4; x++) {
        local_result[x + 2] = tmp_res[x + 2] * COEF[x + 2];
    }
    for (x = 0; x < 6; x++) {
        result += local_result[x];
    }
}
