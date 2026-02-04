#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n2 * 2; i += 1) {
        int acc = 0;
        for (int j = 0; j < 5; ++j) {
            acc += (i + j) * (i + j);
        }
        acc = acc % 100;
    }
}
