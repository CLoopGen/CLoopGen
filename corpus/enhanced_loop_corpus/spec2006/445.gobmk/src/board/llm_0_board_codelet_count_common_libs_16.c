#include <stdio.h>

#include <inttypes.h>

extern int ml[400];
extern int liberty_mark;
extern int *libs1;
extern int liberties1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < liberties1; i++) {
        for (k = i; k <= i; k++)
            ml[libs1[k]] = liberty_mark;
    }
}
