#include <stdio.h>

#include <inttypes.h>

struct dir_info {
    char *path;
    int length;
    int prefix;
    int count;
    int dir_idx;
    int used;
};


extern struct dir_info *dirs;
extern int *saved;
extern int *savehere;
extern int ndirs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ndirs; i++) {
    int j;
    int base_length = dirs[i].length;
    savehere[i] = base_length;
    int diff = base_length - saved[i];
    int total = diff * dirs[i].count;

    for (j = i + 2; j < ndirs; j += 2) {
        savehere[j] = 0;
        savehere[j-1] = 0;

        if (saved[j] < base_length) {
            int k = dirs[j].prefix;
            for (; k != -1 && k > i; ) k = dirs[k].prefix;
            if (k == i) {
                savehere[j] = base_length;
                total += (base_length - saved[j]) * dirs[j].count;
            }
        }
        if (j-1 > i && saved[j-1] < base_length) {
            int k = dirs[j-1].prefix;
            for (; k != -1 && k > i; ) k = dirs[k].prefix;
            if (k == i) {
                savehere[j-1] = base_length;
                total += (base_length - saved[j-1]) * dirs[j-1].count;
            }
        }
    }

    for (; j < ndirs; j++) {
        savehere[j] = 0;
        if (saved[j] < base_length) {
            int k = dirs[j].prefix;
            for (; k != -1 && k != i; ) k = dirs[k].prefix;
            if (k == i) {
                savehere[j] = base_length;
                total += (base_length - saved[j]) * dirs[j].count;
            }
        }
    }

    if (total > base_length + 1) {
        for (j = i; j < ndirs; j++) {
            if (savehere[j] > 0) {
                saved[j] = savehere[j];
                dirs[j].dir_idx = i;
            }
        }
    }
}
}
