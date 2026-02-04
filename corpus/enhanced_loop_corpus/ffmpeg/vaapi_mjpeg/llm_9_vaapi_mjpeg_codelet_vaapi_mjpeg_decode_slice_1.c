#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 50000; i++) {
    volatile int a = i + 1;
    volatile int b = a * a;
    volatile int c = b - i;
}
}
