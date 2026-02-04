#include <stdio.h>

#include <inttypes.h>

extern char **row;
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 5; i >= 0; i--) {
        char* temp = row[i];
        irow[i] = temp;
    }
}
