#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; s[i]; i++) {
        int b = 0;
        int temp_j = 0;
        for (j = 0; sep[j]; j++) {
            if (s[i] == sep[j]) {
                b = 1;
                temp_j = j;  // Introduce a new dependency: WAW on j via temp_j
                break;
            }
        }
        j = temp_j;  // Write to j after loop, creating a loop-carried WAW dependency on j
        if (!b)
            break;
    }
}
