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
    for (i = 0; i < len && src[i] != '\x00'; i += 2) {
        tgt[i] = adj & src[i];
        if (i + 1 < len && src[i + 1] != '\x00') {
            tgt[i + 1] = adj & src[i + 1];
        }
    }
}
