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
int found_start = 0;
for (i = 0; res[i] && !found_start; ++i) {
    if (res[i] == '(') {
        start = res + i + 1;
        found_start = 1;
    }
}
for (; res[i]; ++i) {
    if (res[i] == ')') {
        end = res + i;
        break;
    }
}
}
