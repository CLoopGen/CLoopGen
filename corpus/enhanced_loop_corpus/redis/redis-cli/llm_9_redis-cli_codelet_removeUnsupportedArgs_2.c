#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef enum {
    ARG_TYPE_STRING,
    ARG_TYPE_INTEGER,
    ARG_TYPE_DOUBLE,
    ARG_TYPE_KEY,
    ARG_TYPE_PATTERN,
    ARG_TYPE_UNIX_TIME,
    ARG_TYPE_PURE_TOKEN,
    ARG_TYPE_ONEOF,
    ARG_TYPE_BLOCK
} redisCommandArgType;

struct cliCommandArg {
    char *name;
    redisCommandArgType type;
    char *token;
    char *since;
    int flags;
    int numsubargs;
    struct cliCommandArg *subargs;
    const char *display_text;
    int matched;
    int matched_token;
    int matched_name;
    int matched_all;
};


extern struct cliCommandArg *args;
extern int *numargs;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = *numargs - 1;
    if (i < limit) {
        for (j = i; j < limit; j += 2) {
            args[j] = args[j + 1];
            if (j + 1 < limit) {
                args[j + 1] = args[j + 2];
            }
        }
        // Handle odd-sized range by filling the last element if needed
        for (; j < *numargs - 1; j++) {
            args[j] = args[j + 1];
        }
    }
}
