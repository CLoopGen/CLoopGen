#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; ++i) {
        if (!(i & 1)) 
            row[i] = ((void *)0);
    }
}
