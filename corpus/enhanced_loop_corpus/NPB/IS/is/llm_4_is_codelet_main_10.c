#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE test_index_array[5];
extern INT_TYPE test_rank_array[5];
extern INT_TYPE S_test_index_array[5];
extern INT_TYPE S_test_rank_array[5];
extern INT_TYPE W_test_index_array[5];
extern INT_TYPE W_test_rank_array[5];
extern INT_TYPE A_test_index_array[5];
extern INT_TYPE A_test_rank_array[5];
extern INT_TYPE B_test_index_array[5];
extern INT_TYPE B_test_rank_array[5];
extern INT_TYPE C_test_index_array[5];
extern INT_TYPE C_test_rank_array[5];
extern int i;



void loop(){
for (i = 0; i < 5; i++) {
    test_index_array[i] = A_test_index_array[i];
    test_rank_array[i] = A_test_rank_array[i];
}
}
