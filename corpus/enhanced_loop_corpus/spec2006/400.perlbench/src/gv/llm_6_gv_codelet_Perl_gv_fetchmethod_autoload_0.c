#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *nend;
extern  char *nsplit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_nend = name;
    char *temp_nsplit = NULL;

    for (; *temp_nend; temp_nend++) {
        if (*temp_nend == '\'')
            temp_nsplit = temp_nend;
        else if (*temp_nend == ':' && *(temp_nend + 1) == ':') {
            temp_nend++; // Skip next ':'
            temp_nsplit = temp_nend;
        }
    }
    nsplit = temp_nsplit;
    nend = temp_nend;
}
