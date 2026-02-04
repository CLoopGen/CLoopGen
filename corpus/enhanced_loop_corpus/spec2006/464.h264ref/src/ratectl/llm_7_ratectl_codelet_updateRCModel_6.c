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
    // Variant 2: Eliminate simple loop-carried dependence by unrolling and introducing irregular access
    // Also introduces artificial WAR-like scenario through out-of-order effective execution
    if (20 > 0) m_rgRejected[0] = FALSE;
    if (20 > 1) m_rgRejected[1] = FALSE;
    for (i = 2; i < 20; i += 2) {
        m_rgRejected[i] = FALSE;
        m_rgRejected[i - 1] = FALSE;  // WAR potential: writing previous element later in loop iteration
    }
    // Final cleanup for odd-sized tail (not needed here since 20 is even, but structure shows variation)
}
