#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect access via pointer arithmetic for both arrays
    char *ps = s;
    char *psep;
    i = 0;
    for (; *ps; ps++, i++) {
        int b = 0;
        for (psep = sep; *psep; psep++) {
            if (*ps == *psep) {
                b = 1;
                break;
            }
        }
        if (!b)
            break;
    }
}
