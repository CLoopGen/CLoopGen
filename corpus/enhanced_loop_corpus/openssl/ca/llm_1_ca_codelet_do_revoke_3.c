#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            irow[i * 3 + j] = row[i * 3 + j];
}
