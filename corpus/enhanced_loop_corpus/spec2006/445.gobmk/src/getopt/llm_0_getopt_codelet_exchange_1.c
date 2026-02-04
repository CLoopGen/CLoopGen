#include <stdio.h>

#include <inttypes.h>

extern char **argv;
extern int bottom;
extern int middle;
extern char *tem;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < len; i++) {
    for (j = 0; j < 1; j++) {
        tem = argv[bottom + i];
        argv[bottom + i] = argv[middle + i];
        argv[middle + i] = tem;
    }
}
}
