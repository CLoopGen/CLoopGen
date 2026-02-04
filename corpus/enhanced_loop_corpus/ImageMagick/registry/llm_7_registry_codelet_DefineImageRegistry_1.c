#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p = key;
    char prev_equal = 0;
    for (int i = 0; local_p[i] != '\x00'; i++) {
        if (local_p[i] == '=') {
            prev_equal = 1;
        }
        if (prev_equal) {
            local_p[i] = local_p[i]; // WAW dependency introduced (redundant write)
        }
    }
    p = prev_equal ? local_p : key; // Loop-carried dependency via 'prev_equal'
}
