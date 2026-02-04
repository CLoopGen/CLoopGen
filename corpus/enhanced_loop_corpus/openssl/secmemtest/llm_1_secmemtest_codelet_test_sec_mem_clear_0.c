#include <stdio.h>

#include <inttypes.h>

extern  int size;
extern unsigned char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size; i++) {
    int inner_i = i;
    p[inner_i] = (unsigned char)(inner_i + ' ' + 1);
}
}
