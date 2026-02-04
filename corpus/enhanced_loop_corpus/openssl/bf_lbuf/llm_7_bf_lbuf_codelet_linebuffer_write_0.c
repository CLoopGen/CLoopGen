#include <stdio.h>

#include <inttypes.h>

extern  char *in;
extern int inl;
extern  char *p;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char local_c = '\x00';
    char *local_p;
    for (local_p = in; local_p < in + inl && (local_c = *local_p) != '\n'; local_p++)
        ;
    p = local_p;
    c = local_c;
}
