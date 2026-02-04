#include <stdio.h>

#include <inttypes.h>

extern int lcol;
extern char *s2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < lcol; outer++) {
    for (i = 0; i < 1; i++) {
        if (*s2)
            s2++;
    }
}
}
