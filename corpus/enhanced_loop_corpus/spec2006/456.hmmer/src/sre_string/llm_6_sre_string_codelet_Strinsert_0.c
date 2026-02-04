#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char c;
extern int pos;
extern char oldc;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp;
    for (s = s1 + pos; c; s++) {
        temp = *s;
        *s = c;
        c = temp;
    }
}
