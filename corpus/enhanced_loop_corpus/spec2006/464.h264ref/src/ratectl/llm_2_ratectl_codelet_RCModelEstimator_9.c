#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean m_rgRejected[21];
extern double m_rgQp[21];
extern int n_windowSize;
extern int i;
extern double oneSampleQ;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    int stride = 2;
    int i;
    // First pass: strided access
    for (i = 0; i < n_windowSize; i += stride) {
        if (!m_rgRejected[i])
            oneSampleQ = m_rgQp[i];
    }
    // Second pass: handle any odd-indexed elements if n_windowSize is not divisible by stride
    for (i = 1; i < n_windowSize; i += stride) {
        if (!m_rgRejected[i])
            oneSampleQ = m_rgQp[i];
    }
}
