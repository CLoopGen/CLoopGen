import os
import argparse
import os
from openai import OpenAI
import argparse
import re
import json

client = OpenAI(
    api_key="",
    # sk-343c906378234d3388fc2bee552437e8
    base_url="https://dashscope.aliyuncs.com/compatible-mode/v1",
)


mutate_types = {"type1": "Loop Nesting Alteration: Increase or decrease the max depth of loops.",
                "type2": "Memory Access Pattern Modification: Alter the way arrays are accessed (e.g., change to consecutive, strided, or indirect access).",
                "type3": "Control Dependency Changes: Modify control flow within the loop by either simplifying or removing existing conditional branches (e.g., if, continue) if present, or introducing appropriate control conditions if absent, to create valid and diverse execution paths.",
                "type4": "Data Dependency Variation: Modify data dependencies within the loop by either introducing or removing dependencies (including RAW, WAR, and WAW) and adding or eliminating loop-carried dependencies as appropriate to generate diverse yet semantically valid loop variants.",
                "type5": "Computational Complexity Adjustment: Modify the number of arithmetic operations, change trip count, or modify nested loops to vary computational intensity."}

def get_prompt(original_code, variant_type, loop_count):
    prompt = f""" Given the following loop code:
{original_code}
Generate {loop_count} loop variants based on the following mutation instructions:
{mutate_types[variant_type]}
Do not use `while` or `do while` statements.
Ensure that the code is syntactically correct and self-contained in C.
Return only the mutated loop code(loop()).
Ensure that the generated function name remains unchanged.
Each variant should remain executable, realistic, and reflect distinct loop characteristics.
Return the enhanced code snippets separated by ``` delimiters.
"""
    return prompt


def get_content(input_file):
    with open(input_file, 'r') as f:
        content = f.read()
    return content

def save_file(output_dir, output_file, content, input_file, loop_record, vars_decl, id = 0):

    pattern = r'```c(.*?)```'
    c_blocks = re.findall(pattern, content, re.DOTALL)
    with open(loop_record, 'a') as record_f:  
        for block in c_blocks:
            filename = f"llm_{id}_{output_file}"
            filepath = os.path.join(output_dir, filename)
            with open(filepath, 'w') as f:
                f.write(vars_decl + "\n")
                f.write(block)
            id += 1
            filepath = os.path.relpath(filepath, os.getcwd())
            record_f.write(f"{filepath},{input_file}\n")

def mutate_loop(source_file, output_dir, input_file, loop_record, api_key, base_url, model_name):
    client = OpenAI(
        api_key=api_key,
        base_url=base_url,
    )

    code = get_content(source_file)
    vars_decl = code.split("void loop")[0]
    variants_code = ""
    
    for key in mutate_types.keys():
        prompt = get_prompt(get_content(source_file), key, 2)

        completion = client.chat.completions.create(
            model=model_name,
            messages=[
                {"role": "system", "content": "You are an expert in code generation and compiler optimization."},
                {"role": "user", "content": prompt},
            ],
        )
        variants_code += completion.choices[0].message.content + "\n"
    

    output_file = source_file.split('/')[-1]
    save_file(output_dir, output_file, variants_code, input_file, loop_record, vars_decl, 0)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--loop_record", type=str, required=True, help="loop record file")
    parser.add_argument("--program_name", type=str, help="program name")
    parser.add_argument("--llm_loop_record", type=str, help="new llm loop record file")
    parser.add_argument("--N", type=int, required=True, help="loop variants count")
    parser.add_argument("--api_key", type=str, required=True, help="LLM API key")
    parser.add_argument("--base_url", type=str, required=True, help="LLM API base URL")
    parser.add_argument("--model_name", type=str, required=True, help="LLM model name to use")
    args = parser.parse_args()

    with open(args.loop_record, 'r') as f:
        loops = json.load(f)

    program_name = args.program_name
    for loop in loops:
        loop_path = loop.get("codelet").strip()
        input_file = loop.get("input").strip()
        
        dir_part = os.path.dirname(loop_path)
        output_dir = os.path.join(os.getcwd(), f"enhanced_{program_name}", dir_part)
        os.makedirs(output_dir, exist_ok=True)
        print(f"start mutate loop: {loop_path}")
        mutate_loop(loop_path, output_dir, input_file, args.llm_loop_record, args.api_key, args.base_url, args.model_name)
        print(f"finished mutate loop")


# python3 batch_gen.py --loop_record /home/carpediem/project/bsc/clang_instrument_tool/loopsets/loop_input_record/spec2006.txt --target_loop_prefix /home/carpediem/project/bsc/clang_instrument_tool/llm_loopsets --program_name spec2006 --llm_loop_record /home/carpediem/project/bsc/clang_instrument_tool/llm_loopsets/loop_input_record/llm_spec2006.txt --api_key sk-343c906378234d3388fc2bee552437e8


