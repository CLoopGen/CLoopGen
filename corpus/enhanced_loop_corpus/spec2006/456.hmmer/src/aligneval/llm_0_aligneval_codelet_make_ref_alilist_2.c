#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int *s1_list;
extern int col;
extern int r1;
extern int r2;
extern int *canons1;
extern int lpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; s1[col] != '\x00'; col++) {
        if (!((s1[col]) == ' ' || (s1[col]) == '.' || (s1[col]) == '_' || (s1[col]) == '-' || (s1[col]) == '~') && canons1[r1]) {
            int temp_result = -1;
            for (int check = 0; check < 1; check++) {  // Artificially nested single-iteration loop
                if (!((s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~'))
                    temp_result = r2;
            }
            s1_list[lpos] = temp_result;
            lpos++;
        }
        if (!((s1[col]) == ' ' || (s1[col]) == '.' || (s1[col]) == '_' || (s1[col]) == '-' || (s1[col]) == '~'))
            r1++;
        if (!((s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~'))
            r2++;
    }
}
