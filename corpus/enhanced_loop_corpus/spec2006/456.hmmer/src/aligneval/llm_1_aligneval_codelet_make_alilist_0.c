#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int *s1_list;
extern int col;
extern int r1;
extern int r2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; s1[col] != '\x00'; col++) {
        int cond1 = !((s1[col]) == ' ' || (s1[col]) == '.' || (s1[col]) == '_' || (s1[col]) == '-' || (s1[col]) == '~');
        int cond2 = !((s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~');
        
        if (cond1 || cond2) {
            for (int flag_update = 0; flag_update < (cond1 + cond2); flag_update++) {
                if (flag_update == 0 && cond1) {
                    s1_list[r1] = cond2 ? r2 : -1;
                    r1++;
                }
                if (flag_update >= 1 && cond2) {
                    r2++;
                }
            }
        }
    }
}
