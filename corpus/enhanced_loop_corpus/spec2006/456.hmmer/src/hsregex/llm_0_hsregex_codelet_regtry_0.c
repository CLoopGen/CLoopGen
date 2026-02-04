#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char **stp;
extern char **enp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 10; i > 0; i--) {
    for (j = 0; j < 1; j++) {
        *stp++ = ((void *)0);
        *enp++ = ((void *)0);
    }
}
}
