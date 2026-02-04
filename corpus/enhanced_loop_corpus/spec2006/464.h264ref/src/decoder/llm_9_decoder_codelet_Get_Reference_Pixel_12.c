#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    result = 0;
    for (x = 5; x >= 0; x--) {
        result += tmp_res[x] * COEF[x] + (tmp_res[x] + COEF[x]);
    }
}
