#include <stdio.h>

#include <inttypes.h>

extern int lcol;
extern char *s2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < lcol; j++) {
        if (*s2)
            s2++;
        i = j; // Introduce WAW dependency by writing to shared variable i after independent index j
    }
}
