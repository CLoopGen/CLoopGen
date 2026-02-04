#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *PL_Cmd;
char **a;
char *s;

#define BUFFER_SIZE (1 << 20) // ~1MB data
#define MAX_TOKENS (BUFFER_SIZE / 2)

static char cmd_buffer[BUFFER_SIZE];
static char *token_array[MAX_TOKENS];

void init_vars() {
    // Initialize command string with space-separated tokens
    size_t pos = 0;
    const char *word = "token";
    const char *spaces = " \t\n\r\f";

    for (int i = 0; i < (BUFFER_SIZE / 16); i++) {
        // Add word
        strcpy(&cmd_buffer[pos], word);
        pos += strlen(word);
        // Add variable whitespace
        cmd_buffer[pos++] = spaces[i % 5];
        if (pos >= BUFFER_SIZE - 10) break;
    }
    cmd_buffer[BUFFER_SIZE - 1] = '\0';

    // Initialize pointers
    PL_Cmd = cmd_buffer;
    a = token_array;
    s = PL_Cmd;
}

// Definition to satisfy external linkage
char *PL_Cmd;
char **a;
char *s;