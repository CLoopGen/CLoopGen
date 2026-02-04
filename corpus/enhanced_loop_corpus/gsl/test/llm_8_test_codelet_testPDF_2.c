#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern double edge[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 50; i++) {
        count[2*i] = 0;
        count[2*i + 1] = 0;
        edge[2*i] = 0;
        edge[2*i + 1] = 0;
    }
}
