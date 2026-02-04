#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char c;
extern int pos;
extern char oldc;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (s = s1 + pos; c; s++) {
            oldc = *s;
            *s = c;
            c = oldc;
        }
    }
}
