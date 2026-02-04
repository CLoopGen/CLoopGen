#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *nend;
extern  char *nsplit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (nend = name; *nend; nend++) {
    for (char *temp = nend; temp != nend + 1 && *temp; temp++) {
        if (*temp == '\'')
            nsplit = temp;
        else if (*temp == ':' && *(temp + 1) == ':') {
            nsplit = ++nend;
            break;
        }
    }
}
}
