#include <stdio.h>

#include <inttypes.h>

extern int *data2;
extern int j;
extern  int data2_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < data2_num; i++) {
        for (j = i; j <= i; j++) {
            data2[j] = 2 * j;
        }
    }
}
