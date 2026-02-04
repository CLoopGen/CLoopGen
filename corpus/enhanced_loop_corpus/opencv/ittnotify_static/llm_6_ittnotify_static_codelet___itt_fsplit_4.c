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
    for (; s[i]; (*len)++, i++) {
        int b = 0;
        j = 0;
        for (; sep[j]; j++) {
            if (s[i] == sep[j]) {
                b = 1;
                j = 0; // Introduce WAW dependency on j: write after write
                break;
            }
        }
        if (b) {
            i++; // Introduce additional update to i (WAW on i across iterations)
            break;
        }
        // Add artificial RAW dependency: use updated j from inner loop
        (*len) += (j > 0); // Use final j value (though usually 0 due to break), creates read-after-write
    }
}
