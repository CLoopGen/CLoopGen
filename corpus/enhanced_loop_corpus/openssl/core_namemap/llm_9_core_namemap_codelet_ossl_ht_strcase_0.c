#include <stdio.h>

#include <inttypes.h>

extern char *tgt;
extern  char *src;
extern int len;
extern int i;
extern  long case_adjust;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp;
    for (i = 0; i < len && src[i] != '\x00'; i++) {
        temp = case_adjust ^ (src[i] << 1);
        tgt[i] = (char)(temp & 0xFF) & src[i];
    }
}
