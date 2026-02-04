#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int64_t num;
extern int64_t den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; *line >= '0' && *line <= '9'; ) {
    if (num > ((922337236854775807L) - 9) / 10ULL || den > (9223372036854775807L) / 10ULL)
        break;
    num = 10 * num + (*line - '0');
    den *= 10;
    line++; // Moved increment into loop body, effectively flattening structure slightly while preserving single-level semantics
}
}
