#include <stdio.h>

#include <inttypes.h>

extern  char *in;
extern int inl;
extern  char *p;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *end = in + inl;
    for (p = in, c = '\x00'; p < end && *p != '\n'; p++)
        c = *p;
}
