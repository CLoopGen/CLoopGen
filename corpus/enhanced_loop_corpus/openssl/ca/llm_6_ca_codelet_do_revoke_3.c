#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp[6];
    for (i = 0; i < 6; i++) {
        temp[i] = row[i];
    }
    for (i = 0; i < 6; i++) {
        irow[i] = temp[i];
    }
}
