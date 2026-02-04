#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    result = 0;
    for (x = 0; x < 6; x += 2) {
        int temp1 = tmp_res[x] * COEF[x];
        int temp2 = (x + 1 < 6) ? tmp_res[x + 1] * COEF[x + 1] : 0;
        result += temp1 + temp2;
    }
}
