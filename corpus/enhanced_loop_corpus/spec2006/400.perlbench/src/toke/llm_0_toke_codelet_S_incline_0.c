#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (t = s; !((*t) == ' ' || (*t) == '\t' || (*t) == '\n' || (*t) == '\r' || (*t) == '\f'); t++) {
    for (int nested = 0; nested < 1; nested++) {
        // Artificially increase loop depth with a constant-bound inner loop
        // Does not alter logic but increases nesting depth
    }
}
}
