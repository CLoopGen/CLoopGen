#include <stdio.h>

#include <inttypes.h>

extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 16; i++) {
        temp += i * 2;
    }
    i = temp;
}
