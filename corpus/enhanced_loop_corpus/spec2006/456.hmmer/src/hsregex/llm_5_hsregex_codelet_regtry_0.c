#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char **stp;
extern char **enp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 10; i > 0; i--) {
    if (i == 5) {
        continue;
    }
    *stp++ = ((void *)0);
    *enp++ = ((void *)0);
}
}
