#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    STRLEN local_len = len;
    char *local_d = d;
    for (; local_len && (*local_d == ' ' || *local_d == '\t' || *local_d == '\n' || *local_d == '\r' || *local_d == '\f'); 
         --local_len, ++local_d)
        ;
    len = local_len;
    d = local_d;
}
