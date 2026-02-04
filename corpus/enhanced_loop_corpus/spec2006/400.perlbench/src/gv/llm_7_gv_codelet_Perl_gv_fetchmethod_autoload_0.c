#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *nend;
extern  char *nsplit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_nend = name;
    char *candidate = nsplit;

    for (; local_nend < nend || *local_nend; local_nend++) {
        if (*local_nend == '\'' && (candidate == NULL || local_nend > candidate))
            candidate = local_nend;
        else if (*local_nend == ':' && *(local_nend + 1) == ':') {
            local_nend++;
            if (candidate == NULL || local_nend > candidate)
                candidate = local_nend;
        }
    }

    nsplit = candidate;
    nend = local_nend;
}
