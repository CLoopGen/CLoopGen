#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *nend;
extern  char *nsplit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (nend = name; *nend; nend++) {
        if (*nend == '\'') {
            nsplit = nend;
        } else {
            if (*(nend + 1) == ':') {
                if (*nend == ':') {
                    nsplit = ++nend;
                }
            }
        }
    }
}
