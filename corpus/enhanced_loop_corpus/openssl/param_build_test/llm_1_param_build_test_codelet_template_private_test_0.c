#include <stdio.h>

#include <inttypes.h>

extern int *data1;
extern int j;
extern  int data1_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (data1_num > 0) {
        for (j = 0; j < data1_num; j += 2) {
            data1[j] = -16 * j;
            if (j + 1 < data1_num) {
                data1[j + 1] = -16 * (j + 1);
            }
        }
    }
}
