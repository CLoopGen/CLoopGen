#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *nend;
extern  char *nsplit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every second character)
    char *nend_temp = name;
    // Process characters with a stride of 2
    for (nend = nend_temp; *nend; nend += 2) {
        if (*nend == '\'')
            nsplit = nend;
        else if (*nend == ':' && *(nend + 1) == ':')
            nsplit = ++nend;
    }
    // Handle odd positions by scanning remaining elements in a second pass
    for (nend = name + 1; *nend; nend += 2) {
        if (*nend == '\'')
            nsplit = nend;
        else if (*nend == ':' && *(nend + 1) == ':')
            nsplit = ++nend;
    }
}
