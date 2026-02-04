#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int *chr;
extern int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = length - 2; j >= 0; j--) {
        int temp_j = j;
        for (int k = 0; k < 1; k++) {
            *chr = *chr * 10 + dig[temp_j];
        }
    }
}
