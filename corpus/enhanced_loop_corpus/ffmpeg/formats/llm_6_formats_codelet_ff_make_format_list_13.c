#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_count = 0;
    while (1) {
        int val = fmts[temp_count];
        if (val == -1) break;
        temp_count++;
    }
    count = temp_count;
}
