#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

int reload_n_operands;
HARD_REG_ELT_TYPE reload_reg_used_in_input_addr[30];
HARD_REG_ELT_TYPE reload_reg_used_in_inpaddr_addr[30];
HARD_REG_ELT_TYPE reload_reg_used_in_output_addr[30];
HARD_REG_ELT_TYPE reload_reg_used_in_outaddr_addr[30];
HARD_REG_ELT_TYPE reload_reg_used_in_input[30];
HARD_REG_ELT_TYPE reload_reg_used_in_output[30];
int i;

void init_vars() {
    reload_n_operands = 30;
    for (int j = 0; j < 30; j++) {
        reload_reg_used_in_input_addr[j] = 0;
        reload_reg_used_in_inpaddr_addr[j] = 0;
        reload_reg_used_in_output_addr[j] = 0;
        reload_reg_used_in_outaddr_addr[j] = 0;
        reload_reg_used_in_input[j] = 0;
        reload_reg_used_in_output[j] = 0;
    }
    i = 0;
}