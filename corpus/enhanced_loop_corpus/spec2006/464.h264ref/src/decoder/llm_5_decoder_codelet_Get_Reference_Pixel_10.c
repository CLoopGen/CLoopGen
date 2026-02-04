#include <stdio.h>

#include <inttypes.h>

extern int y;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = -2; y < 4; y++) {
        if (COEF[y + 2] == 0) {
            continue;
        }
        result += tmp_res[y + 2] * COEF[y + 2];
    }
}
