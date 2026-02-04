#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double P[];
extern double num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4; i >= 0; --i) {
        num = x * num + P[i];
        if (i == 2) {
            num = num * 1.1;
        }
    }
}
