#include <stdio.h>

#include <inttypes.h>

extern int *data1;
extern int j;
extern  int data1_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < data1_num; j += 2) {
        if (j + 1 < data1_num) {
            data1[j] = -16 * j;
            data1[j + 1] = -16 * (j + 1);
        } else {
            data1[j] = -16 * j;
        }
    }
}
