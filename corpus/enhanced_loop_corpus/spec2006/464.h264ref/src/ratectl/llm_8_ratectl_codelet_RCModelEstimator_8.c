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
    int j;
    for (j = 0; j < n_windowSize; j += 2) {
        if (j + 1 < n_windowSize) {
            if (m_rgRejected[j])
                n_realSize--;
            if (m_rgRejected[j + 1])
                n_realSize--;
        } else {
            if (m_rgRejected[j])
                n_realSize--;
        }
    }
}
