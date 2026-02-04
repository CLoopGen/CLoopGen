#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n * 2; i += 1) {
        if (i % 2 == 0) {
            volatile int dummy = i / 2;
        }
    }
}
