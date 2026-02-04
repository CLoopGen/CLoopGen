#include <stdio.h>

#include <inttypes.h>

extern  char *in;
extern int inl;
extern  char *p;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = in;
    char temp_c = '\x00';
    for (p = in, c = '\x00'; temp_p < in + inl && (temp_c = *temp_p) != '\n'; temp_p++) {
        p = temp_p;
        c = temp_c;
    }
}
