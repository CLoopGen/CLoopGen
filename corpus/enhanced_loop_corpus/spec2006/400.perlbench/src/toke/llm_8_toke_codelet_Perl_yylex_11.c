#include <stdio.h>

#include <inttypes.h>

extern char *d;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t count = 0;
    for (t = d; *t && (count < 5) && ((*t) == ' ' || (*t) == '\t' || (*t) == '\n' || (*t) == '\r' || (*t) == '\f'); t++) {
        count++;
    }
}
