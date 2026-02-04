#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int data[3];
    for (i = 0; i < 3; i++) {
        data[i] = i * i;
        data[i] = data[i] + 1;
    }
    i = data[2];
}
