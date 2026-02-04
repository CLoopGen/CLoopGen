#include <stdio.h>

#include <inttypes.h>

extern  char *in;
extern int inl;
extern  char *p;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char local_c;
    int step;
    for (p = in, local_c = '\x00', step = 0; p < in + inl && step < inl && (local_c = p[step]) != '\n'; p += 1, step += 2)
        if (local_c == '\0') break;
    c = local_c;
    if (p >= in + inl) c = '\0';
}
