#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int c;
extern int t;
extern int ii;
extern int jj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_ii = ii;
    int temp_jj = jj;
    for (i = 0; i < j; i++) {
        temp_ii = (temp_ii + 1);
        if (temp_ii >= t)
            temp_ii = 0;
        temp_jj = (temp_jj + 2);
        if (temp_jj >= c) {
            temp_jj = 0;
        }
    }
    ii = temp_ii;
    jj = temp_jj;
}
