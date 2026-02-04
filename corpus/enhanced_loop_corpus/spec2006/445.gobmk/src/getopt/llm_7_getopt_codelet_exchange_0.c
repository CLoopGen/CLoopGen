#include <stdio.h>

#include <inttypes.h>

extern char **argv;
extern int bottom;
extern int middle;
extern int top;
extern char *tem;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = top - (middle - bottom);
    for (i = len - 1; i >= 0; i--) {
        tem = argv[bottom + i];
        argv[bottom + i] = argv[offset + i];
        argv[offset + i] = tem;
    }
}
