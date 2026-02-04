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
    for (i = 0; j < len && s[j]; j++, i++) {
        // Remove direct self-dependence on 'i' in condition by using 'j'; introduce RAW: j used before i updated
        // Loop-carried dependency now on 'j', with 'i' shadowing 'j'
    }
    i = j;  // Reconcile final value of i to match original semantics indirectly
}
