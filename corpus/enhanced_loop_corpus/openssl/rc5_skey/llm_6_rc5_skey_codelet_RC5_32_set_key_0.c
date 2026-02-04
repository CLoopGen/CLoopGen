#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
    for (i = 0; i <= (len - 8); i += 8) {
        temp1 += i;
        temp2 += temp1;
        temp3 += temp2;
        temp4 += temp3;
    }
}
