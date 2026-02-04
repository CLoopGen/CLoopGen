#include <stdio.h>

#include <inttypes.h>

extern char *tgt;
extern  char *src;
extern int len;
extern int i;
extern  long case_adjust;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; src[i] != '\x00' && i < len; i++) {
    for (j = 0; j < 1; j++) {
        tgt[i] = case_adjust & src[i];
    }
}
}
