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
        if (!((k1[col]) == ' ' || (k1[col]) == '.' || (k1[col]) == '_' || (k1[col]) == '-' || (k1[col]) == '~')) {
            for (int nested = 0; nested < 1; nested++) {
                canons1[r1] = ref[col] ? 1 : 0;
                r1++;
            }
        }
    }
}
