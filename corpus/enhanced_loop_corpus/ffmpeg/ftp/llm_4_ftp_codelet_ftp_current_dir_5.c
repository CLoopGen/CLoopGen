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
        if (res[i] == '"' && !start) {
            start = res + i + 1;
        }
        else if (res[i] == '"' && start) {
            end = res + i;
            break;
        }
    }
}
