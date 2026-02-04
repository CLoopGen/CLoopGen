#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *res;
extern char *start;
extern char *end;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_start = NULL;
    int found_open = 0;
    for (i = 0; res[i]; ++i) {
        if (!found_open && res[i] == '(') {
            temp_start = res + i + 1;
            found_open = 1;  // Introduce WAW dependency: found_open written once
        }
        if (found_open && res[i] == ')') {
            start = temp_start;        // RAW: depends on temp_start and found_open
            end = res + i;
            break;
        }
    }
}
