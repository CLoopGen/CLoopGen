#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ext;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = 6;
for (int i = 0; i < limit; i += 2) {
    char val = (*ext == '\x00') ? ' ' : *ext++;
    p[i % 3] = val;
}
}
