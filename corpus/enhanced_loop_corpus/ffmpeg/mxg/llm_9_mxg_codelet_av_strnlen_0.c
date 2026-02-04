#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing by 2 each time, with bounds check
    for (i = 0; i < len && s[i]; i += 2) {
        if (i + 1 >= len || !s[i + 1]) {
            break;
        }
    }
    // Adjust final value of i to maintain logical equivalence in scanning null-terminated string up to len
    if (i < len && !s[i]) i--;
}
