#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

Boolean m_rgRejected[21];
int i;

void init_vars() {
    // Initialize all elements of m_rgRejected to FALSE
    for (int j = 0; j < 21; j++) {
        m_rgRejected[j] = FALSE;
    }
    // Initialize loop index variable
    i = 0;
}