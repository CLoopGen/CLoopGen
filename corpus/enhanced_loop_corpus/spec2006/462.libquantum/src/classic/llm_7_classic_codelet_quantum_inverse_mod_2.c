#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 1, j = 1; (j * c) % n != 1; i++, j++) {
        j = i;
    }
}
