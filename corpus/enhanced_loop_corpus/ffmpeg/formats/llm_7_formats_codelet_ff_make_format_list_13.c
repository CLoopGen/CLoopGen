#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    count = 0;
    for (i = 0; ; i++) {
        int current = fmts[i];
        if (current == -1) {
            break;
        }
        count = i + 1;
    }
}
