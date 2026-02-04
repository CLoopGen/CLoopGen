#include <stdio.h>

#include <inttypes.h>

extern int *data2;
extern int j;
extern  int data2_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j < data2_num; j++) {
        data2[j] = data2[j-1] + 2;
    }
    if (data2_num > 0) {
        data2[0] = 0;
    }
}
