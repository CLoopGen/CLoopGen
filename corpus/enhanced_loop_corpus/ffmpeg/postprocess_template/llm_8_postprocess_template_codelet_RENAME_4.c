#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
for (i = 0; i < 1000; i++) {
    for (j = 0; j < 50; j++) {
        x += i * j + 2;
    }
}
}
