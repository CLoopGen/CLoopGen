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
    for (i = 0; i < n_windowSize; i++) {
        if (m_rgRejected[i]) {
        } else {
            oneSampleQ = m_rgQp[i];
        }
    }
}
