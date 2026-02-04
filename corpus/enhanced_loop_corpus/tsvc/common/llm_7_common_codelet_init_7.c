#include <stdio.h>

#include <inttypes.h>

extern int **ip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *p = *ip;
    int temp1, temp2, temp3, temp4, temp5;
    for (int i = 0; i < 32000; i += 5) {
        temp1 = (i + 4);
        temp2 = (i + 2);
        temp3 = (i);
        temp4 = (i + 3);
        temp5 = (i + 1);
        p[i] = temp1;
        p[i + 1] = temp2;
        p[i + 2] = temp3;
        p[i + 3] = temp4;
        p[i + 4] = temp5;
    }
}
