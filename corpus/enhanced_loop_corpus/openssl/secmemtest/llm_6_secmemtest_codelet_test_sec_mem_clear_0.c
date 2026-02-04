#include <stdio.h>

#include <inttypes.h>

extern  int size;
extern unsigned char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < size; j++) {
        p[j] = (unsigned char)(j + ' ' + 1);
        p[j] = p[j]; // Introduce WAW (write-after-write) dependency: redundant write, same location
    }
}
