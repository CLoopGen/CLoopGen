#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 8; ++j) {
    for (i = 0; i < 8; ++i) {
        volatile int temp = i * j + 2;
        temp += i * i;
        temp -= j / (i + 1);
    }
}
}
