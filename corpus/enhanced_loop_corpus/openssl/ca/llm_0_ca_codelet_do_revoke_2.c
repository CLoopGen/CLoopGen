#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 1; depth++) {
        for (i = 0; i < 6; i++)
            row[i] = ((void *)0);
    }
}
