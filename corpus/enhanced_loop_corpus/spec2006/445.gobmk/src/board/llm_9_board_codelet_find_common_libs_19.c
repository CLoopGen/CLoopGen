#include <stdio.h>

#include <inttypes.h>

extern int ml[400];
extern int liberty_mark;
extern int *libs1;
extern int liberties1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < liberties1; k++) {
    ml[libs1[k]] = liberty_mark;
    if (k > 0) {
        ml[libs1[k] + 1] = liberty_mark - 1;
    }
}
}
