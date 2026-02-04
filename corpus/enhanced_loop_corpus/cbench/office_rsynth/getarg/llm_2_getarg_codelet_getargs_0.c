#include <stdio.h>

#include <inttypes.h>

extern int j;
extern int argc;
extern char *argv[];
extern int i;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    // Instead of forward traversal, iterate backward to modify access pattern
    for (j = argc; j >= i; j--)
        argv[j] = argv[j + off];
}
