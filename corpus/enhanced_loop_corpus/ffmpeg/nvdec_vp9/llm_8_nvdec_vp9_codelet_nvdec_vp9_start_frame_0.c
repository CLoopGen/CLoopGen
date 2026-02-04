#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 1000; i++) {
    for (j = 0; j < 10; j++) {
        volatile int temp = i * j + 5 - 2;
    }
}
}
