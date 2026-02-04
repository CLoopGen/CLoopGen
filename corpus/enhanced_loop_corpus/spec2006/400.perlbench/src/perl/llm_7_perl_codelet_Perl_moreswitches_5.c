#include <stdio.h>

#include <inttypes.h>

extern char *e;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_e = p;
    char current;
    for (current = *local_e; current && !(current == ' ' || current == '\t' || current == '\n' || current == '\r' || current == '\f'); current = *(++local_e))
        ;
    e = local_e;
}
