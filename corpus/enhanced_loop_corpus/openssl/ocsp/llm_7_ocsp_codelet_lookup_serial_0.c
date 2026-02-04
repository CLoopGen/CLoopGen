#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char *row[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    row[0] = ((void *)0);
    for (i = 1; i < 6; i++) {
        row[i] = ((void *)0);
        row[i-1] = row[i]; // Introduce WAW and WAR dependency; redundant but creates loop-carried dependence
    }
    row[5] = ((void *)0); // Ensure final state matches original semantics
}
