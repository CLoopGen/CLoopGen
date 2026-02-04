#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int *surround_size;
extern char mn[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++)
    if ((board[pos] != 3) && mn[pos] == 1)
        (*surround_size)++;

}
