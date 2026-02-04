#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char **stp;
extern char **enp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i++) {
    *(stp + i) = ((void *)0);
}
for (i = 0; i < 10; i++) {
    *(enp + i) = ((void *)0);
}
}
