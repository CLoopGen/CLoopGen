#include <stdio.h>

#include <inttypes.h>

extern char **row;
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 12; i += 2) {
        irow[i] = row[i];
        if (i + 1 < 6) 
            irow[i + 1] = row[i + 1];
    }
}
