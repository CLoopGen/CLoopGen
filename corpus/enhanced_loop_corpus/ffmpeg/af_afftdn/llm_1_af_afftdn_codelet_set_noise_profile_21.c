#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            sum += temp[i * 3 + j];
}
