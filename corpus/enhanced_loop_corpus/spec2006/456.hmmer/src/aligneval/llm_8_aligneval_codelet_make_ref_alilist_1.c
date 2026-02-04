#include <stdio.h>

#include <inttypes.h>

extern int *ref;
extern char *k1;
extern int col;
extern int r1;
extern int *canons1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; k1[col] != '\x00' && col < 1024; col++) {
        int ch = k1[col];
        int is_valid = (ch == ' ' || ch == '.' || ch == '_' || ch == '-' || ch == '~');
        if (!is_valid) {
            canons1[r1] = ref[col] ? 1 : 0;
            r1++;
        }
    }
}
