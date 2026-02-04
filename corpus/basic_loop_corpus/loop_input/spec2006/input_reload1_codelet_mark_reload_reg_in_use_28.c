#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

enum reload_type {
    RELOAD_FOR_INPUT,
    RELOAD_FOR_OUTPUT,
    RELOAD_FOR_INSN,
    RELOAD_FOR_INPUT_ADDRESS,
    RELOAD_FOR_INPADDR_ADDRESS,
    RELOAD_FOR_OUTPUT_ADDRESS,
    RELOAD_FOR_OUTADDR_ADDRESS,
    RELOAD_FOR_OPERAND_ADDRESS,
    RELOAD_FOR_OPADDR_ADDR,
    RELOAD_OTHER,
    RELOAD_FOR_OTHER_ADDRESS
};

HARD_REG_ELT_TYPE reload_reg_used = 0;
HARD_REG_ELT_TYPE reload_reg_used_in_input_addr[30] = {0};
HARD_REG_ELT_TYPE reload_reg_used_in_inpaddr_addr[30] = {0};
HARD_REG_ELT_TYPE reload_reg_used_in_output_addr[30] = {0};
HARD_REG_ELT_TYPE reload_reg_used_in_outaddr_addr[30] = {0};
HARD_REG_ELT_TYPE reload_reg_used_in_input[30] = {0};
HARD_REG_ELT_TYPE reload_reg_used_in_output[30] = {0};
HARD_REG_ELT_TYPE reload_reg_used_in_op_addr = 0;
HARD_REG_ELT_TYPE reload_reg_used_in_op_addr_reload = 0;
HARD_REG_ELT_TYPE reload_reg_used_in_insn = 0;
HARD_REG_ELT_TYPE reload_reg_used_in_other_addr = 0;
HARD_REG_ELT_TYPE reload_reg_used_at_all = 0;
unsigned int regno = 0;
int opnum = 0;
enum reload_type type = RELOAD_FOR_INPUT;
unsigned int nregs = 64;
unsigned int i = 0;

void init_vars() {
    regno = 0;
    nregs = 64;
    opnum = 0;
    type = RELOAD_FOR_INPUT;

    reload_reg_used = 0;
    for (int j = 0; j < 30; j++) {
        reload_reg_used_in_input_addr[j] = 0;
        reload_reg_used_in_inpaddr_addr[j] = 0;
        reload_reg_used_in_output_addr[j] = 0;
        reload_reg_used_in_outaddr_addr[j] = 0;
        reload_reg_used_in_input[j] = 0;
        reload_reg_used_in_output[j] = 0;
    }
    reload_reg_used_in_op_addr = 0;
    reload_reg_used_in_op_addr_reload = 0;
    reload_reg_used_in_insn = 0;
    reload_reg_used_in_other_addr = 0;
    reload_reg_used_at_all = 0;
}