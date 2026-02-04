#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean m_rgRejected[21];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2
    // Initialize even indices first, then odd indices in a second pass
    for (int stride = 0; stride < 2; stride++) {
        for (i = stride; i < 20; i += 2) {
            m_rgRejected[i] = FALSE;
        }
    }
}
