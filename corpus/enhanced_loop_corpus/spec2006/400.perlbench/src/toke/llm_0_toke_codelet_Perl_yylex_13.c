#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; len; --len, ++d) {
    if ((*d) == ' ' || (*d) == '\t' || (*d) == '\n' || (*d) == '\r' || (*d) == '\f') break;
}
}
