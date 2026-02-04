#include <stdio.h>

#include <inttypes.h>

extern int *ref;
extern char *k1;
extern int col;
extern int r1;
extern int *canons1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_r1 = r1;
    for (col = 0; k1[col] != '\x00'; col++) {
        int condition = !((k1[col]) == ' ' || (k1[col]) == '.' || (k1[col]) == '_' || (k1[col]) == '-' || (k1[col]) == '~');
        if (condition) {
            canons1[temp_r1] = ref[col] ? 1 : 0;
            temp_r1++;
        }
    }
    r1 = temp_r1;
}
