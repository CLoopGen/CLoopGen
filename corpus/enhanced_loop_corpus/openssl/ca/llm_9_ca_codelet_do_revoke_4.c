#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 12; i++) {
        j = i / 2;
        if (j < 6)
            row[j] = ((void *)0);
    }
}
