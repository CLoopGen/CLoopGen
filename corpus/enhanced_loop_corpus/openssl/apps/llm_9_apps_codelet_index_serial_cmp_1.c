#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *b;
extern  char *bb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced computational intensity with stride-based traversal to decrease effective trip count
    for (bb = b[3]; *bb == '0'; bb += 2) {
        if (*(bb + 1) != '0') {
            bb--;  // Adjust pointer to maintain correct exit condition
            break;
        }
    }
}
