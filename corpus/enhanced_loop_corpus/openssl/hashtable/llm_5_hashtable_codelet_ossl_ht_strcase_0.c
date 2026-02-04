#include <stdio.h>

#include <inttypes.h>

extern char *tgt;
extern  char *src;
extern int len;
extern int i;
extern  long case_adjust;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && src[i] != '\x00'; i++) {
        char val = src[i];
        if (val >= 'a' && val <= 'z') {
            tgt[i] = case_adjust & val;
        } else if (val >= 'A' && val <= 'Z') {
            tgt[i] = case_adjust & (val + ('a' - 'A'));
        } else {
            tgt[i] = case_adjust & val;
        }
    }
}
