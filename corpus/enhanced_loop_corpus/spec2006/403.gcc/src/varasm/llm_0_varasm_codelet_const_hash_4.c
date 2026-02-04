#include <stdio.h>

#include <inttypes.h>

extern  char *p;
extern int hi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; p[i] != 0; i++) {
    for (j = 0; j < 1; j++) {
        hi = ((hi * 613) + (unsigned int)(p[i]));
    }
}
}
