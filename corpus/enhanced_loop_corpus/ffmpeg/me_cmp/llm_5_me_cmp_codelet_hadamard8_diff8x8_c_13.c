#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[64];
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int skip_first_pair = (i == 1 || i == 3 || i == 5 || i == 7);
    if (!skip_first_pair) {
        {
            int a, b;
            a = temp[8 * 0 + i];
            b = temp[8 * 1 + i];
            temp[8 * 0 + i] = a + b;
            temp[8 * 1 + i] = a - b;
        }
        {
            int a, b;
            a = temp[8 * 2 + i];
            b = temp[8 * 3 + i];
            temp[8 * 2 + i] = a + b;
            temp[8 * 3 + i] = a - b;
        }
    }

    {
        int a, b;
        a = temp[8 * 4 + i];
        b = temp[8 * 5 + i];
        temp[8 * 4 + i] = a + b;
        temp[8 * 5 + i] = a - b;
    }
    {
        int a, b;
        a = temp[8 * 6 + i];
        b = temp[8 * 7 + i];
        temp[8 * 6 + i] = a + b;
        temp[8 * 7 + i] = a - b;
    }

    if (i != 2 && i != 6) {
        {
            int a, b;
            a = temp[8 * 0 + i];
            b = temp[8 * 2 + i];
            temp[8 * 0 + i] = a + b;
            temp[8 * 2 + i] = a - b;
        }
        {
            int a, b;
            a = temp[8 * 1 + i];
            b = temp[8 * 3 + i];
            temp[8 * 1 + i] = a + b;
            temp[8 * 3 + i] = a - b;
        }
    }

    {
        int a, b;
        a = temp[8 * 4 + i];
        b = temp[8 * 6 + i];
        temp[8 * 4 + i] = a + b;
        temp[8 * 6 + i] = a - b;
    }
    {
        int a, b;
        a = temp[8 * 5 + i];
        b = temp[8 * 7 + i];
        temp[8 * 5 + i] = a + b;
        temp[8 * 7 + i] = a - b;
    }

    int val_sum = 0;
    int t0 = temp[8 * 0 + i], t4 = temp[8 * 4 + i];
    int t1 = temp[8 * 1 + i], t5 = temp[8 * 5 + i];
    int t2 = temp[8 * 2 + i], t6 = temp[8 * 6 + i];
    int t3 = temp[8 * 3 + i], t7 = temp[8 * 7 + i];

    val_sum += (t0 + t4) >= 0 ? (t0 + t4) : -(t0 + t4);
    val_sum += (t0 - t4) >= 0 ? (t0 - t4) : -(t0 - t4);
    val_sum += (t1 + t5) >= 0 ? (t1 + t5) : -(t1 + t5);
    val_sum += (t1 - t5) >= 0 ? (t1 - t5) : -(t1 - t5);
    val_sum += (t2 + t6) >= 0 ? (t2 + t6) : -(t2 + t6);
    val_sum += (t2 - t6) >= 0 ? (t2 - t6) : -(t2 - t6);
    val_sum += (t3 + t7) >= 0 ? (t3 + t7) : -(t3 + t7);
    val_sum += (t3 - t7) >= 0 ? (t3 - t7) : -(t3 - t7);

    sum += val_sum;
}
}
