#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char **stp;
extern char **enp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_i;
for (i = 10; i > 0; i--) {
    temp_i = i - 1;
    stp[temp_i] = ((void *)0);
    enp[temp_i] = ((void *)0);
}
}
