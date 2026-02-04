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
    for (int i = 0; i < 4096 && local_p[i] != '\x00'; i++) {
        if (local_p[i] == '=') {
            prev_equal = 1;
        }
        if (prev_equal) {
            local_p = &local_p[i];
            break;
        }
    }
    p = local_p;
}
