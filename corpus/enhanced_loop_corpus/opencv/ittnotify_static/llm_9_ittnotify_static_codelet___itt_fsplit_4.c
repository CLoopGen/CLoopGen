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
    for (; s[i]; i += 2, (*len) += 2) {
        int b = 0;
        int c = 0;
        for (j = 0; sep[j]; j++) {
            if (i + 1 < *len && s[i] == sep[j]) {
                b = 1;
            }
            if (i + 1 < *len && s[i + 1] == sep[j]) {
                c = 1;
            }
        }
        if (b || c)
            break;
        if (s[i + 1] == '\0')
            break;
    }
    // Adjust final length if last char was skipped
    if (s[i] && !s[i + 1]) (*len)++;
}
