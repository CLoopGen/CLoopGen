#include <stdio.h>

#include <inttypes.h>

extern int *data1;
extern int j;
extern  int data1_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= data1_num; j++)
        data1[j-1] = -16 * j;
}
