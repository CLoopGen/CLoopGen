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
    for (i = 0; res[i] && i < 1024; ++i) {
        if ((res[i] == '(') && (i + 1 < 1024)) {
            start = res + i + 1;
            i += 1; // Artificially increase step under condition to reduce effective trip count
        } else if (res[i] == ')') {
            end = res + i;
            break;
        }
    }
}
