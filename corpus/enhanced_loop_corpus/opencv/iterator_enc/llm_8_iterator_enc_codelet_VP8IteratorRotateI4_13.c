#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i <= 100; ++i) {
    for (j = 0; j < 5; ++j) {
        i += j * 2;
    }
}
}
