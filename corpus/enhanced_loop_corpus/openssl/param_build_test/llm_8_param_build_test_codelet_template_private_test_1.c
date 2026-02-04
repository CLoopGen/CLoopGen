#include <stdio.h>

#include <inttypes.h>

extern int *data2;
extern int j;
extern  int data2_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < data2_num; j += 2) {
        if (j + 1 < data2_num) {
            data2[j] = 4 * j;
            data2[j + 1] = 4 * j + 2;
        } else {
            data2[j] = 4 * j;
        }
    }
}
