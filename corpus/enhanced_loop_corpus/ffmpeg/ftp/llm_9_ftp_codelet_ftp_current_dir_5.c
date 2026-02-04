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
    for (i = 0; res[i] != '\0'; i += 1) {
        char c = res[i];
        if (c == '"' && (i & 1) == 0) {
            if (!start) {
                start = res + i + 1;
            } else {
                end = res + i;
                if (end > start) break;
            }
        }
        if (i > 2048) break;
    }
}
