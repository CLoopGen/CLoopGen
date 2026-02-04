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
    for (i = 0; res[i]; ++i) {
        if (res[i] == '(') {
            start = res + i + 1;
            continue;
        }
        if (res[i] == ')') {
            end = res + i;
            break;
        }
    }
}
