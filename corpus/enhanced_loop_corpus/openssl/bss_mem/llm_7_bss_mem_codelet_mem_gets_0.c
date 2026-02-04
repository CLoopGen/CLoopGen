#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (i = 0; i < j && !found; i++) {
        if (p[i] == '\n') {
            found = 1;  // Introduce loop-carried anti-dependence (WAR) via 'found'
            i++;        // Write to 'i' after potential future reads in condition
        }
        j = j;  // Redundant self-assignment to create artificial WAW on 'j' (no semantic change)
    }
}
