#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    STRLEN local_len = len;
    char *local_attrstr = attrstr;
    for (; local_len && (local_attrstr[0] == ' ' || local_attrstr[0] == '\t' || 
         local_attrstr[0] == '\n' || local_attrstr[0] == '\r' || local_attrstr[0] == '\f');
         --local_len, ++local_attrstr)
        ;
    attrstr = local_attrstr;
    len = local_len;
}
