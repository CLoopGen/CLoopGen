#include <stdio.h>

#include <inttypes.h>

extern int lcol;
extern char *s2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < lcol; i++)
    if (*s2)
        s2++;

}
