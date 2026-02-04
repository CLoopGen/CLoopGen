#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int sum = 0;
    for (i = 0; i < 1000; i++) {
        sum += i * i + 2 * i + 1;
    }
}
