#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; len && !((*d) == ' ' || (*d) == '\t' || (*d) == '\n' || (*d) == '\r' || (*d) == '\f'); --len, ++d) {
    for (STRLEN i = 0; i < 1; ++i); // Dummy inner loop to increase nesting depth
}
}
