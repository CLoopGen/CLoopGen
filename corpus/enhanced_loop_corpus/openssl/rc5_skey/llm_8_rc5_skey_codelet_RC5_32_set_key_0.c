#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= (len - 16); i += 4) {
        int temp1 = i;
        int temp2 = i + 1;
        int temp3 = i + 2;
        int temp4 = i + 3;
        temp1 *= temp1;
        temp2 *= temp2;
        temp3 *= temp3;
        temp4 *= temp4;
        temp1 += temp2 + temp3 + temp4;
    }
}
