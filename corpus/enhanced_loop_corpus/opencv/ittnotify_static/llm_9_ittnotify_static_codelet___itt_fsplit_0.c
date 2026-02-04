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
    for (i = 0; s[i]; i += 2) {  // Increment by 2 to reduce trip count and increase stride
        int b = 0;
        for (j = 0; sep[j]; j++) {
            if (s[i] == sep[j]) {
                b = 1;
                break;
            }
        }
        if (!b && i > 0) {  // Delay break condition to increase computation per iteration
            for (j = 0; sep[j]; j++) {
                if (s[i - 1] == sep[j]) {
                    b = 1;
                    break;
                }
            }
            if (!b)
                break;
        }
    }
}
