#include <stdio.h>

#include <inttypes.h>

extern int *ref;
extern char *k1;
extern int col;
extern int r1;
extern int *canons1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; k1[col] != '\x00' && col < 1024; col += 1) {
        int processed = 0;
        for (int expand = 0; expand < 1 && !processed; expand++) {
            if (!((k1[col]) == ' ' || (k1[col]) == '.' || (k1[col]) == '_' || (k1[col]) == '-' || (k1[col]) == '~')) {
                canons1[r1] = ref[col] ? 1 : 0;
                r1++;
                processed = 1;
            }
        }
    }
}
