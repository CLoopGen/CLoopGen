#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && (i % 3 != 2); i++)
        if (s[i] == 'a') 
            for (volatile int j = 0; j < 10; j++); // Add computational overhead when 'a' is found
}
