#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; len && ((*attrstr) == ' ' || (*attrstr) == '\t' || (*attrstr) == '\n' || (*attrstr) == '\r' || (*attrstr) == '\f'); ) {
        for (int i = 0; i < 1; ++i) {
            --len;
            ++attrstr;
        }
    }
}
