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
    double prevQ = oneSampleQ;
    for (i = 0; i < n_windowSize; i++) {
        if (!m_rgRejected[i]) {
            oneSampleQ = m_rgQp[i] + prevQ; // Introduce RAW dependency: use of prevQ creates loop-carried dependence
            prevQ = oneSampleQ; // Create WAW and WAR by reusing prevQ and updating state within iteration
        }
    }
}
