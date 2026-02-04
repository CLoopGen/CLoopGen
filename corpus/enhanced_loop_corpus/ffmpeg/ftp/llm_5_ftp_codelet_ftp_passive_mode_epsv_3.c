#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *res;
extern char *start;
extern char *end;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; res[i] && !(res[i] == ')' && (end = res + i, 1)); ++i) {
        res[i] == '(' ? (start = res + i + 1) : (void)0;
    }
}
