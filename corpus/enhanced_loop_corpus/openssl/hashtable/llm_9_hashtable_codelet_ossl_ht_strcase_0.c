#include <stdio.h>

#include <inttypes.h>

extern char *tgt;
extern  char *src;
extern int len;
extern int i;
extern  long case_adjust;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long adj = case_adjust;
    for (i = 0; src[i] != '\x00' && i < len; i++) {
        tgt[i] = ((adj ^ src[i]) + (src[i] & 0x20)) & src[i];
    }
}
