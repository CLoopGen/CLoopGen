#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer i__;
integer ic;
char subnam[6] = {0};

void init_vars() {
    subnam[0] = 'a';
    subnam[1] = '\xe1'; 
    subnam[2] = '\xe9'; 
    subnam[3] = '\xed'; 
    subnam[4] = '\xf3'; 
    subnam[5] = '\xfa'; 
}