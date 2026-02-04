#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int *len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; s[i]; i++, (*len)++) {
        int b = 0;
        int temp_j = 0;
        for (j = 0; sep[j]; j++) {
            if (s[i] == sep[j]) {
                b = 1;
                temp_j = j;  // Introduce a new dependency: WAW on j via temp_j
                break;
            }
        }
        if (b) {
            j = temp_j;  // Create a loop-carried WAR dependency: use of j after potential overwrite
            break;
        }
        j = temp_j + 1;  // Add artificial write to j, creating a WAW dependency across iterations
    }
}
