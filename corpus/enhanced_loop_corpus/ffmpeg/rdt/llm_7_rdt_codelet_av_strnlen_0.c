#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char val;
    for (i = 0; i < len; i++) {
        val = s[i];  // Load into local variable to create temporary storage
        if (!val) break;  // Check condition after load, introducing a data dependency on 'val'
        // This version separates the array load from the branch decision, creating a stronger RAW dependency on 'val'
        // Loop-carried dependence is preserved via 'i', but memory access and exit condition are now split
    }
}
