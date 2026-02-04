#include <stdio.h>

#include <inttypes.h>

extern int ml[400];
extern int liberty_mark;
extern int *libs1;
extern int liberties1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (k = 0; k < liberties1 * 2; k += 2) {
    i = libs1[k / 2];
    ml[i] = liberty_mark;
    ml[i + 1] = liberty_mark;
}
}
