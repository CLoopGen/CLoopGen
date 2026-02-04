#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (count = 0; fmts[count] != -1; count++)
    ;

}
