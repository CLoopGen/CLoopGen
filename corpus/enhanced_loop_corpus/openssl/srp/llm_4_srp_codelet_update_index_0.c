#include <stdio.h>

#include <inttypes.h>

extern char **row;
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; ++i) {
        if (row[i] != NULL)
            irow[i] = row[i];
    }
}
