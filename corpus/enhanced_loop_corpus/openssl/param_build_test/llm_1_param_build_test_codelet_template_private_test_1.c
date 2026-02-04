#include <stdio.h>

#include <inttypes.h>

extern int *data2;
extern int j;
extern  int data2_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (data2_num > 0) {
        j = 0;
        for (; j < data2_num; ) {
            data2[j] = 2 * j;
            j++;
        }
    }
}
