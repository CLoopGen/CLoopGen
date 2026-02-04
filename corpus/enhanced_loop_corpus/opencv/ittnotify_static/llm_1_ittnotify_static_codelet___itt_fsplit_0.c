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
    for (i = 0; s[i]; i++) {
        int b = 1;
        for (j = 0; sep[j] && b; j++) {
            for (int k = 0; k < 1; k++) {  // Artificially increased nesting depth
                if (s[i] == sep[j]) {
                    b = 0;
                    break;
                }
            }
        }
        if (b)
            break;
    }
}
