#include <stdio.h>
#include <inttypes.h>

enum bb_state {
    NOT_IN_BB,
    IN_ONE_BB,
    IN_MULTIPLE_BB
};

int i;
int max_uid;
int *start;
int *end;
enum bb_state *in_bb_p;

static int start_buf[65536];
static int end_buf[65536];
static enum bb_state in_bb_p_buf[65536];

void init_vars() {
    max_uid = 65536;
    start = start_buf;
    end = end_buf;
    in_bb_p = in_bb_p_buf;
}