#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int max_v;
extern int *c_array;
extern  int arraysize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_max = c_array[0];
for (x = 1; x < arraysize; x += 2) {
    if (x + 1 < arraysize) {
        int val1 = c_array[x];
        int val2 = c_array[x + 1];
        if (val1 > val2) {
            if (val1 > temp_max)
                temp_max = val1;
        } else {
            if (val2 > temp_max)
                temp_max = val2;
        }
    } else {
        if (c_array[x] > temp_max)
            temp_max = c_array[x];
    }
}
max_v = temp_max;
}
