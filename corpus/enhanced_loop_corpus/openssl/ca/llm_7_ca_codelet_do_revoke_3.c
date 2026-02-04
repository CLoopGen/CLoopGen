#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 5; i >= 0; i--) {
        irow[i] = row[i];
        row[i] = NULL; // Introduce WAW and WAR dependency by modifying source after use
    }
}
