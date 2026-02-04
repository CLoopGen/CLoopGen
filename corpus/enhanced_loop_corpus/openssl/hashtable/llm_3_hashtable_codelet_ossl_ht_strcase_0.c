#include <stdio.h>

#include <inttypes.h>

extern char *tgt;
extern  char *src;
extern int len;
extern int i;
extern  long case_adjust;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[256];
    int count = 0;
    for (i = 0; src[i] != '\x00' && i < len && count < 256; i++) {
        indices[count++] = i;
    }
    for (i = 0; i < count; i++) {
        int idx = indices[i];
        tgt[idx] = case_adjust & src[idx];
    }
}
