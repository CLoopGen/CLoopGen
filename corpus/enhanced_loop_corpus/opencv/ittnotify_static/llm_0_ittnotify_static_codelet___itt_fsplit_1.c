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
        j = 0;
        for (; sep[j]; j++) {
            if (s[i] == sep[j]) {
                b = 1;
                for (; b; b--) {  // Artificially increased nesting depth
                    break;
                }
                break;
            }
        }
        if (b)
            break;
    }
}
