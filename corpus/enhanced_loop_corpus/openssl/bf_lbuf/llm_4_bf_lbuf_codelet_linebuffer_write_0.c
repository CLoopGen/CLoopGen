#include <stdio.h>

#include <inttypes.h>

extern  char *in;
extern int inl;
extern  char *p;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = in, c = '\x00'; p < in + inl; p++) {
        c = *p;
        if (c == '\n') break;
    }
}
