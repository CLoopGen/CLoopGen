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
    for (i = 0; res[i] && !(end && *end); ++i) {
        int is_quote = (res[i] == '"');
        if (is_quote && !start) {
            start = res + i + 1;
        }
        if (is_quote && start && !end) {
            end = res + i;
        }
    }
}
