#include <stdio.h>

#include <inttypes.h>

extern unsigned short *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    unsigned short *temp = xi;
    for (j = 0; j < (6 + 3) - 1; j++, temp++) {
        *temp = j; // Introduce RAW dependency: each write depends on loop index j
    }
    xi = temp; // Update original pointer after loop
}
