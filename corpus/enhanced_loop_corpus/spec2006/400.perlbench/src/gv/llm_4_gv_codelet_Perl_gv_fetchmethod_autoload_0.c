#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *nend;
extern  char *nsplit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (nend = name; *nend; nend++) {
        if (*nend != '\'' && (*nend != ':' || *(nend + 1) != ':')) 
            continue;
        if (*nend == '\'')
            nsplit = nend;
        else if (*nend == ':' && *(nend + 1) == ':') {
            nsplit = ++nend;
        }
    }
}
