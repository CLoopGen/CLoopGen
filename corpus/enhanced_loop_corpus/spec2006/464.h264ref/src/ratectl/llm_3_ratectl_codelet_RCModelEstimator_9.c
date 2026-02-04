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
    // Variant 2: Reverse Consecutive Memory Access (traverse array from end to start)
    int i;
    for (i = n_windowSize - 1; i >= 0; i--) {
        if (!m_rgRejected[i])
            oneSampleQ = m_rgQp[i];
    }
}
