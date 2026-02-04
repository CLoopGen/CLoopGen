#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

Boolean m_rgRejected[21];
int n_windowSize;
int n_realSize;
int i;

void init_vars() {
    n_windowSize = 21;
    n_realSize = 21;
    for (i = 0; i < 21; i++) {
        m_rgRejected[i] = (i % 3 == 0) ? TRUE : FALSE;
    }
    i = 0;
}