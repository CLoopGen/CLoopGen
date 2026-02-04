#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *nend;
extern  char *nsplit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (nend = name; *nend && *(nend + 1); nend += 2) {
        if (*nend == '\'' && *(nend + 1) != '\0')
            nsplit = nend;
        else if (*nend == ':' && *(nend + 1) == ':') {
            nsplit = nend;
            nend++;
        }
    }
    // Handle last character if needed
    if (nend > name && *nend && !*(nend + 1)) {
        if (*nend == '\'')
            nsplit = nend;
    }
}
