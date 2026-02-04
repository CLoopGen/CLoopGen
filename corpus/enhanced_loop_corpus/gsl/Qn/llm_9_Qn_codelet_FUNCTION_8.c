#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ni; i++) {
        int temp_left = ni - i;
        int temp_right_base = i - h;
        left[i] = temp_left + 2;
        right[i] = (temp_right_base <= 0) ? ni : ni - temp_right_base + 1;
        if (i % 2 == 0 && i > 0) {
            left[i-1] += 1;
        }
    }
}
