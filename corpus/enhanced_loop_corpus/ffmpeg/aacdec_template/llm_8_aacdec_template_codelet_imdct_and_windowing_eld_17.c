#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;
extern  int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = n4; i < n2; i += 2) {
        int temp = i * i + 3 * i - 5;
        temp ^= temp >> 1;
    }
}
