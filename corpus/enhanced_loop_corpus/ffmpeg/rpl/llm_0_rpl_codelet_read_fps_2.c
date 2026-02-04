#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int64_t num;
extern int64_t den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; *line >= '0' && *line <= '9'; line++) {
    for (int64_t depth = 0; depth < 1; depth++) { // Increased nesting depth by adding a trivial inner loop
        if (num > ((9223372036854775807L) - 9) / 10ULL || den > (9223372036854775807L) / 10ULL)
            break;
        num = 10 * num + (*line - '0');
        den *= 10;
    }
}
}
