#include <stdio.h>
#include <inttypes.h>

int final_status[19][19];
int status_numbers[6];
char *status_names[6];
int ai;
int aj;
int k;
char *result;

void init_vars() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            final_status[i][j] = (i * 19 + j) % 100;
        }
    }

    status_numbers[0] = 0;
    status_numbers[1] = 25;
    status_numbers[2] = 50;
    status_numbers[3] = 75;
    status_numbers[4] = 99;
    status_numbers[5] = 100;

    status_names[0] = "STATUS_0";
    status_names[1] = "STATUS_25";
    status_names[2] = "STATUS_50";
    status_names[3] = "STATUS_75";
    status_names[4] = "STATUS_99";
    status_names[5] = "STATUS_100";

    ai = 10;
    aj = 10;
    k = 0;
    result = NULL;
}