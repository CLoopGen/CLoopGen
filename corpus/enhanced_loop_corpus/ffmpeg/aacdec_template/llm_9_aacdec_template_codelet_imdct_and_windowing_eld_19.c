#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n4 * n4; i++) {
        int acc = 0;
        for (int j = 0; j < 5; j++) {
            acc += i % (j + 1);
        }
    }
}
