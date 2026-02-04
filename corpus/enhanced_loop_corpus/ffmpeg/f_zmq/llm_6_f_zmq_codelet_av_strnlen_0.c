#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; j < len && s[j]; i++, j++) {
        // Introduce a new induction variable j that breaks direct dependency of updates on i
        // RAW dependency between s[j] and j, WAW on i and j removed from being updated in same expression
        // Loop-carried dependency now split across i and j, both progressing in tandem but i is now indirectly updated
    }
}
