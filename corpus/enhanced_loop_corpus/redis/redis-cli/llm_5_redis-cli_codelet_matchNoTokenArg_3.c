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

typedef struct cliCommandArg {
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
} cliCommandArg;

extern cliCommandArg *arg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_matched_all = arg->matched_all;
    for (i = 0; i < arg->numsubargs && temp_matched_all != 0; i++) {
        temp_matched_all &= arg->subargs[i].matched_all;
    }
    arg->matched_all = temp_matched_all;
}
