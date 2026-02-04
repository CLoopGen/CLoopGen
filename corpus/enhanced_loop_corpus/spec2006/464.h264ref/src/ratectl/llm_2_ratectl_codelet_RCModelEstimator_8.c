#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean m_rgRejected[21];
extern int n_windowSize;
extern int n_realSize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, then handle odd size if needed)
    int stride = 2;
    int i;
    // First pass: even indices
    for (i = 0; i < n_windowSize; i += stride) {
        if (m_rgRejected[i])
            n_realSize--;
    }
    // Second pass: odd indices, if any
    for (i = 1; i < n_windowSize; i += stride) {
        if (m_rgRejected[i])
            n_realSize--;
    }
}
