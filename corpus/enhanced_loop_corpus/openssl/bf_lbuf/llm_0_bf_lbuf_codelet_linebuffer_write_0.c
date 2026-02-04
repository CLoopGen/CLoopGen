#include <stdio.h>

#include <inttypes.h>

extern  char *in;
extern int inl;
extern  char *p;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p;
    char temp_c;
    for (p = in, c = '\x00'; p < in + inl; p++) {
        temp_c = *p;
        if (temp_c == '\n') {
            c = temp_c;
            break;
        }
        for (temp_p = p; temp_p < p + 1; temp_p++) {
            c = *temp_p;
        }
    }
}
