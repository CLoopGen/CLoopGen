#include <stdio.h>

#include <inttypes.h>

extern int *ref;
extern char *k1;
extern int col;
extern int r1;
extern int *canons1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; k1[col] != '\x00'; col++) {
        int is_valid = (k1[col]) == ' ' || (k1[col]) == '.' || (k1[col]) == '_' || (k1[col]) == '-' || (k1[col]) == '~';
        if (!is_valid) {
            if (ref[col]) {
                canons1[r1] = 1;
            } else {
                canons1[r1] = 0;
            }
            r1++;
        }
    }
}
