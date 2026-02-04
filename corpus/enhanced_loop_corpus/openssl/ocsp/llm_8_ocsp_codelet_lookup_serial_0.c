#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char *row[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 12; i += 2) {
    row[i/2] = ((void *)0);
}
}
