#include <stdio.h>

#include <inttypes.h>

extern char *PL_Cmd;
extern char **a;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided-like indirect access via index with bounds checking, using only for-loops
    int i = 0;
    int start;
    int len = 0;
    char *cmd = PL_Cmd;

    // Precompute length of command string
    for (len = 0; cmd[len]; ++len);

    for (i = 0; i < len;) {
        // Skip whitespaces
        for (; i < len && (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\n' || cmd[i] == '\r' || cmd[i] == '\f'); ++i);

        // Mark start of token
        start = i;

        // Skip non-whitespace
        for (; i < len && !(cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\n' || cmd[i] == '\r' || cmd[i] == '\f'); ++i);

        // If valid token, store pointer and null-terminate
        if (start != i && start < len) {
            *(a++) = &cmd[start];
            if (i < len) {
                cmd[i++] = '\x00';
            }
        }
    }
}
