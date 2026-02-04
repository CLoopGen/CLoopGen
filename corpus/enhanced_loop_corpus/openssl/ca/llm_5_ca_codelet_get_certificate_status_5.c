#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 5; i >= 0; --i) {
        row[i] = ((void *)0);
    }
}
