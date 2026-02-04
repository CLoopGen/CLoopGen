#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    row[0] = ((void *)0);
    for (i = 1; i < 6; i++) {
        row[i] = ((void *)0);
        row[i] = row[i-1]; // Introduce WAW and RAW loop-carried dependency
    }
}
