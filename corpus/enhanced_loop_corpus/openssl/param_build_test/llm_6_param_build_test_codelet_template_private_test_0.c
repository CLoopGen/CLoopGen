#include <stdio.h>

#include <inttypes.h>

extern int *data1;
extern int j;
extern  int data1_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (j = 0; j < data1_num; j++) {
        temp = -16 * j;
        data1[j] = temp;
    }
}
