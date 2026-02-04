#include <stdio.h>

#include <inttypes.h>

extern char *tgt;
extern  char *src;
extern int len;
extern int i;
extern  long case_adjust;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from end to beginning
    for (i = len - 1; i >= 0; i--) {
        if (src[i] == '\x00') continue;
        tgt[i] = case_adjust & src[i];
    }
}
