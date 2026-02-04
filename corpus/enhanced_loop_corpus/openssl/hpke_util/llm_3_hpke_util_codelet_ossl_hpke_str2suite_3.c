#include <stdio.h>

#include <inttypes.h>

extern  char *suitestr;
extern char *st;
extern int delim_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using array indexing instead of pointer arithmetic
    int i;
    for (i = 0; ((char *)suitestr)[i] != '\x00'; i++) {
        if (((char *)suitestr)[i] == ',')
            delim_count++;
    }
}
