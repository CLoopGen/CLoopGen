#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef int integer;

integer i__;
integer ic;
char subnam[6];

void init_vars() {
    i__ = 0;
    ic = 0;
    memset(subnam, 0, 6);
    // Initialize subnam with sample values that trigger the transformation
    // Choose values in ranges: 129-137, 145-153, 162-169
    subnam[0] = 'A'; // 65
    subnam[1] = (char)130;
    subnam[2] = (char)150;
    subnam[3] = (char)165;
    subnam[4] = (char)132;
    subnam[5] = '\0';
}