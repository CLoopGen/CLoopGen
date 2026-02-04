#include <stdio.h>

#include <inttypes.h>

extern int *ref;
extern char *k1;
extern int col;
extern int r1;
extern int *canons1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; k1[col] != '\x00'; col += 2) {
        if (col + 1 < 256) {
            int cond1 = !((k1[col]) == ' ' || (k1[col]) == '.' || (k1[col]) == '_' || (k1[col]) == '-' || (k1[col]) == '~');
            int cond2 = !((k1[col+1]) == ' ' || (k1[col+1]) == '.' || (k1[col+1]) == '_' || (k1[col+1]) == '-' || (k1[col+1]) == '~');
            if (cond1) {
                canons1[r1] = ref[col] ? 1 : 0;
                r1++;
            }
            if (cond2) {
                canons1[r1] = ref[col+1] ? 1 : 0;
                r1++;
            }
        } else {
            if (!((k1[col]) == ' ' || (k1[col]) == '.' || (k1[col]) == '_' || (k1[col]) == '-' || (k1[col]) == '~')) {
                canons1[r1] = ref[col] ? 1 : 0;
                r1++;
            }
        }
    }
}
