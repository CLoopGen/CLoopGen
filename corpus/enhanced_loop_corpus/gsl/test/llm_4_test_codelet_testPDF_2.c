#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern double edge[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 100; ++i) {
        count[i] = 0;
        if (i % 2 == 0) {
            edge[i] = 0;
        }
    }
}
