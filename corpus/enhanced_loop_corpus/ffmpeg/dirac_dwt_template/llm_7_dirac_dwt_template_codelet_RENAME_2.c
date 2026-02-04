#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2 / 2; x++) {
        int temp = x;
        for (int y = 0; y < 3; y++) {
            temp = temp * temp + y;
        }
        (void)temp;
    }
}
