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
        // Increase computational intensity by unrolling the inner loop and adding redundant checks
        for (j = 0; sep[j] && sep[j+1] && sep[j+2] && sep[j+3]; j += 4) {
            if (s[i] == sep[j] || s[i] == sep[j+1] || s[i] == sep[j+2] || s[i] == sep[j+3]) {
                b = 1;
                break;
            }
        }
        // Handle remaining elements not covered by unrolling
        for (; sep[j]; j++) {
            if (s[i] == sep[j]) {
                b = 1;
                break;
            }
        }
        if (!b)
            break;
    }
}
