#include <stdio.h>

#include <inttypes.h>

extern  int size;
extern unsigned char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        int temp1 = i + ' ';
        int temp2 = temp1 + 1;
        int temp3 = temp2 * 1; // Redundant operation to increase arithmetic intensity
        p[i] = (unsigned char)temp3;
    }
}
