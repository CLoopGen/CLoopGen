#include <stdio.h>

#include <inttypes.h>

extern char *d;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (t = d; *t; t++) {
        char found_non_whitespace = 0;
        if ((*t) != ' ' && (*t) != '\t' && (*t) != '\n' && (*t) != '\r' && (*t) != '\f') {
            found_non_whitespace = 1;
        }
        if (found_non_whitespace) {
            break;
        }
    }
}
