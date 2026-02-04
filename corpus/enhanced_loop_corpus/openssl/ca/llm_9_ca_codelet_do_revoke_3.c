#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 3; i++) {
        j = 2 * i;
        irow[j] = row[j];
        irow[j + 1] = row[j + 1];
    }
}
