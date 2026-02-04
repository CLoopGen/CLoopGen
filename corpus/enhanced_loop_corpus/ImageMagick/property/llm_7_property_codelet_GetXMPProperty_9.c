#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *xmp_profile;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p = xmp_profile;
    int found = 0;
    for (; !found && *local_p != '\x00'; local_p++) {
        char c1 = *local_p;
        char c2 = *(local_p + 1);
        if ((c1 == '<') && (c2 == 'x')) {
            found = 1;
        }
        p = local_p; // WAW dependency introduced: p is updated each iteration, last write wins
    }
    if (!found)
        p = local_p;
}
