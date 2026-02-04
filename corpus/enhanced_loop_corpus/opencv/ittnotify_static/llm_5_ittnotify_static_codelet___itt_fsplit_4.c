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
for (; s[i] && !(*len); i++ , (*len)++) {
    for (j = 0; sep[j]; j++)
        if (s[i] == sep[j]) {
            (*len) = 0;
            goto end_loop;
        }
}
end_loop:
i--;
}
