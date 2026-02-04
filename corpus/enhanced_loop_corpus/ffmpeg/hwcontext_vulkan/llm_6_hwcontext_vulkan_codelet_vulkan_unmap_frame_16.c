#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int planes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (int i = 0; i < planes; i++) {
        temp += i;
    }
    // Introduces a loop-carried dependency (WAW on `temp`)
    // RAW and WAW dependencies exist due to `temp` being read and written in each iteration
}
