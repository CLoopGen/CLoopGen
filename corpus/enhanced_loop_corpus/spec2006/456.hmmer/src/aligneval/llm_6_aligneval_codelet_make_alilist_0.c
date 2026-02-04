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
    int temp_r1 = r1;
    int temp_r2 = r2;
    for (col = 0; s1[col] != '\x00'; col++) {
        int cond1 = !((s1[col]) == ' ' || (s1[col]) == '.' || (s1[col]) == '_' || (s1[col]) == '-' || (s1[col]) == '~');
        int cond2 = !((s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~');
        
        if (cond1) {
            s1_list[temp_r1] = cond2 ? -1 : temp_r2;
            temp_r1++;
        }
        if (cond2) {
            temp_r2++;
        }
    }
    r1 = temp_r1;
    r2 = temp_r2;
}
