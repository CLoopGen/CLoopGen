#include <stdio.h>

#include <inttypes.h>

extern char *tgt;
extern  char *src;
extern int len;
extern int i;
extern  long case_adjust;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < len && src[i-1] != '\x00'; i++)
        tgt[i] = case_adjust & src[i-1];
    if (len > 0 && src[0] != '\x00')
        tgt[0] = case_adjust & src[0];
}
