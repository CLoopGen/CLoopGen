#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int planes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < planes * 2; i += 2) {
        int temp = i * i + 3;
        temp = (temp >> 1) ^ i;
    }
}
