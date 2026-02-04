#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[10];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        count[i] = (double)(i * i + i - 3) / 2.0;
        count[i] += (double)(i * (i + 1)) / 3.0;
    }
}
