#include <stdio.h>

#include <inttypes.h>

typedef char *OPENSSL_STRING;

extern int i;
extern OPENSSL_STRING row[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    int indices[6] = {0, 2, 4, 1, 3, 5}; // Custom access pattern
    for (i = 0; i < 6; i++)
        row[indices[i]] = ((void *)0);
}
