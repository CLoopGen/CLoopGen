#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *b;
extern  char *bb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index array (simulated with fixed indices)
    static const int indices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // example indices
    int i = 0;
    bb = b[3];
    for (; i < 10 && bb[indices[i]] == '0'; i++) {
        continue; // side-effect free iteration
    }
    bb += indices[i]; // set bb to the position where condition failed
}
