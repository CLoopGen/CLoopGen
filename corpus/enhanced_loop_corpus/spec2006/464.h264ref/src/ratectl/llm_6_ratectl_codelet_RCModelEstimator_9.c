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
    double tempQ = oneSampleQ; // Introduce temporary to modify data dependency
    for (i = 0; i < n_windowSize; i++) {
        if (!m_rgRejected[i])
            tempQ = m_rgQp[i]; // Eliminate direct write to shared variable in loop
    }
    oneSampleQ = tempQ; // Write final value after loop (removes WAW and RAW loop-carried deps)
}
