#include <stdio.h>

#include <inttypes.h>

extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_t = t;
    for (; ((*local_t) == ' ' || (*local_t) == '\t' || (*local_t) == '\n' || (*local_t) == '\r' || (*local_t) == '\f'); local_t++)
        ;
    t = local_t;
}
