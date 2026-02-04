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
    // Variant 1: Introduce loop-carried WAW dependency and RAW dependency via delayed write
    Boolean temp[20];
    for (i = 0; i < 20; i++) {
        temp[i] = FALSE;
    }
    for (i = 0; i < 20; i++) {
        m_rgRejected[i] = temp[i];  // WAW: m_rgRejected written after temp initialized; RAW on temp[i]
    }
}
