#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 6; i++) {
        row[i] = ((void *)0);
        for (j = 0; j < 5; j++) {
            // Dummy arithmetic to increase computational intensity
            volatile int dummy = i * j + 2;
            (void)dummy;
        }
    }
}
