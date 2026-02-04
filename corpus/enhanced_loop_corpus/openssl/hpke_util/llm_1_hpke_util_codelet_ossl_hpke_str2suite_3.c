#include <stdio.h>

#include <inttypes.h>

extern  char *suitestr;
extern char *st;
extern int delim_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop that runs exactly once to simulate altered loop structure without changing logic
    for (int outer = 0; outer < 1 && suitestr != NULL; outer++) {
        for (st = (char *)suitestr; *st != '\x00'; st++) {
            if (*st == ',')
                delim_count++;
        }
    }
}
