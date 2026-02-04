#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char **stp;
extern char **enp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 20; i > 0; i -= 2) {
    for (j = 0; j < 3; j++) {
        *stp++ = ((void *)0);
        *enp++ = ((void *)0);
    }
}
}
