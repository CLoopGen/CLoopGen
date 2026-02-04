#include <stdio.h>

#include <inttypes.h>

extern int lcol;
extern char *s2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = lcol - 1; i >= 0; i--) {
    if (*s2 && i % 2 == 0)
        s2++;
}
}
