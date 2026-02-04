#include <stdio.h>

#include <inttypes.h>

typedef char *OPENSSL_STRING;

extern int i;
extern OPENSSL_STRING row[6];
extern OPENSSL_STRING *irow;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index mapping (reverse order traversal)
    const int indices[6] = {5, 4, 3, 2, 1, 0};
    for (i = 0; i < 6; i++) {
        int idx = indices[i];
        irow[idx] = row[idx];
    }
}
