#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double J[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int index = i * 10 + j;
            J[index] = index * 20;
        }
    }
}
