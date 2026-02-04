#include <stdio.h>

#include <inttypes.h>

extern int *data2;
extern int j;
extern  int data2_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < data2_num; j++) {
        if (j % 2 == 0) {
            data2[j] = 2 * j;
        } else {
            data2[j] = 2 * j + 1;
        }
    }
}
