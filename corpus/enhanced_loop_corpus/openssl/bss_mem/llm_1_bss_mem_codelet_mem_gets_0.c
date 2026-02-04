#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < j && p[i] != '\n'; i++) { // Decreased nesting depth: removed inner control, flattened logic
        // Condition merged into loop guard, no nested blocks
    }
    if (i < j && p[i] == '\n') {
        i++;
    }
}
