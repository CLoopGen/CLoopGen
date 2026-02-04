#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *bdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 1; i < top; i++) {
        temp = bdp[i-1]; // Introduce RAW dependency: current iteration reads previous write
        bdp[i] = temp;   // WAW and WAR dependencies partially preserved but modified
    }
}
