#include <stdio.h>

#include <inttypes.h>

extern char *d;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *index = d;
    char found_non_whitespace = 0;
    for (; !found_non_whitespace && *index; ) {
        char c = *index;
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '\f') {
            found_non_whitespace = 1;
        } else {
            index++;
        }
    }
    t = index;
}
