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
    for (i = 0; i < 20; i++) {
        m_rgRejected[i] = FALSE;
        if (i == 9) {
            i += 1; // Skip the next iteration naturally by incrementing index
        }
    }
}
