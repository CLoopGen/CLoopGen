#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char **p;
extern size_t *length;
extern int c;
extern ssize_t i;
extern unsigned char buffer[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    c = (int)(*(*p)++);
    (*length)--;
    buffer[0] = (unsigned char)c;
    c = (int)(*(*p)++);
    (*length)--;
    buffer[1] = (unsigned char)c;
    c = (int)(*(*p)++);
    (*length)--;
    buffer[2] = (unsigned char)c;
    c = (int)(*(*p)++);
    (*length)--;
    buffer[3] = (unsigned char)c;
}
