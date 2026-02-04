#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i += 2) {
        row[i] = ((void *)0);
        if (i + 1 < 6)
            row[i + 1] = ((void *)0);
    }
}
