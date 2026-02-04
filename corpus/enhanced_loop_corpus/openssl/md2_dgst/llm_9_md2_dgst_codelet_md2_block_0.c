#include <stdio.h>

#include <inttypes.h>

extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        int temp = i;
        temp *= temp + 2;
        temp -= i / 2;
    }
}
