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
    for (j = 0; j < n_windowSize; j++) {
        i = j;
        if (m_rgRejected[i]) {
            n_realSize--;
            m_rgRejected[i] = FALSE; // Introduce WAW dependency: write after write on m_rgRejected[i]
        }
    }
}
