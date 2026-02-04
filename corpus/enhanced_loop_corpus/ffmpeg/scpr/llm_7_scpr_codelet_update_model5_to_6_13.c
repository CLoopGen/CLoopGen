#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_d = d;
    int local_e = 0;
    for (; local_d <= 2048; local_d <<= 1, local_e++);
    e = local_e;
}
