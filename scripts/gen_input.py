import argparse
import subprocess
from openai import OpenAI
import tempfile
import os
from pathlib import Path
import json


def get_prompt_with_error(code, error_message=None):
    base_instructions = f"""Given the following loop code:
{code}

generate a self-contained C source file that defines and initializes all those external symbols. The output must satisfy the following:
- Include necessary headers.
- Define all extern variables referenced in the loop (including const pointers, integers, and array pointers) at file scope with correct types.
- Please pay attention to the legality of initializing const variables.
- Place other generated initialization code in a function named init_vars(). 
- Uses a data size that ensures the original loop runs in approximately 0.01 seconds on a typical modern CPU (suggest 1MB–256MB of input data unless the length is specified when the array is declared)
- Initialize appropriate loop boundaries to ensure that memory access inside the loop does not go out of bounds at runtime.

- The code must be compilable with Clang and link with provided loop code. Ensure that when the main() function in other files calls loop(), it can run properly.
- Do NOT include main(), headers, explanations or comments.
Generate the initialization file content based on the variable declarations implied by the loop context.
"""
    # - Place the memory free code in a function named free_vars(), but the init_vars() should not call free_vars().

    if error_message:
        base_instructions += f"\n\nThe previous attempt failed with the following compilation or run errors:\n{error_message}\n\nFix these errors and regenerate the code."
    
    return base_instructions


def compile_and_test(loop_file: str, init_code: str, main_file:str, temp_dir: str):
    """
    Try to compile loop.c + generated init.c + minimal main.c.
    Returns (success: bool, error_output: str)
    """
    # Write generated init.c
    init_path = os.path.join(temp_dir, "init.c")
    with open(init_path, 'w') as f:
        f.write(init_code)

    # Compile all together
    output_exe = os.path.join(temp_dir, "test_loop")
    try:
        result = subprocess.run(
            ["clang", "-O3",
             loop_file, init_path, main_file, "-o", output_exe, "-lm"],
            # cwd=temp_dir,
            capture_output=True,
            text=True,
            timeout=30
        )
        if result.returncode == 0:
            run_result = subprocess.run(
                [output_exe],
                cwd=temp_dir,
                capture_output=True,
                text=True,
                timeout=30
            )
            if run_result.returncode == 0:
                return True, ""
            else:
                if run_result.returncode < 0:
                    import signal
                    signal_name = signal.Signals(-run_result.returncode).name
                    print(f"Program terminated by signal: {signal_name} (returncode={run_result.returncode})")
                    return False, f"Program terminated by signal: {signal_name}"
                else:
                    print(f"Run failed with exit code {run_result.returncode}")
                    return False, f"Run failed with exit code {run_result.returncode}:\n{run_result.stderr}\n{run_result.stdout}"
        else:
            return False, result.stderr + result.stdout
    except subprocess.TimeoutExpired:
        return False, "Compilation or run timed out."
    except FileNotFoundError:
        raise RuntimeError("clang not found. Please install Clang.")


def get_model_response(prompt: str, base_url: str, api_key: str, model_name: str) -> str:

    client = OpenAI(
        api_key=api_key,
        base_url=base_url,
    )

    completion = client.chat.completions.create(
        model=model_name,
        messages=[
            {"role": "system", "content": "You are a code generator that produces C initialization files for compiler optimization evaluation."},
            {"role": "user", "content": prompt},
        ],
    )
    return completion.choices[0].message.content.strip()


def generate_with_retry(loop_code: str, loop_file_path: str, main_file_path:str, max_retries: int, 
                        base_url: str, api_key: str, model_name:str) -> str:
    error_msg = None
    for attempt in range(max_retries):
        print(f"[Attempt {attempt + 1}/{max_retries}] Generating init.c...")
        prompt = get_prompt_with_error(loop_code, error_msg)
        init_code = get_model_response(prompt, base_url, api_key, model_name)

        # Extract only code block if model wraps in ```c ... ```
        if init_code.startswith("```c"):
            init_code = "\n".join(init_code.splitlines()[1:-1])

        # Create temp dir for compilation
        with tempfile.TemporaryDirectory() as tmpdir:
            success, compile_err = compile_and_test(loop_file_path, init_code, main_file_path, tmpdir)
            if success:
                print("Compilation and run succeeded!")
                return init_code
            else:
                error_msg = compile_err[:2000]  # Truncate very long errors
                print(f"Compilation or run failed:\n{error_msg}\n")
                if attempt == max_retries - 1:
                    print("- Max retries reached. Returning last attempt.")
                    print(f"fail loop file: {loop_file_path}")
                    return None
    return init_code 

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate and validate C init code with iterative error feedback.")
    parser.add_argument("--main_file", type=str, required=True, help="Path to main.c if needed for testing")
    parser.add_argument("--loopset_file", type=str, required=True, help="Path to loopset file")
    parser.add_argument("--output_dir", type=str, required=True, help="Output directory for generated init.c files")
    parser.add_argument("--output", type=str, required=True, help="loop and input record file")
    parser.add_argument("--fail_loops_file", type=str, default="", help="File to record failed loops")
    parser.add_argument("--max_retries", type=int, default=5, help="Max number of generation attempts")
    parser.add_argument("--api_key", type=str, required=True, help="LLM API key")
    parser.add_argument("--base_url", type=str, required=True, help="LLM API base URL")
    parser.add_argument("--model_name", type=str, required=True, help="LLM model name to use")
    args = parser.parse_args()
    os.makedirs(args.output_dir, exist_ok=True)

    loop_input_map = []
    fail_loops = []

    with open(args.loopset_file, 'r') as f:
        loopset_lines = f.readlines()
    
    success_count = 0

    for idx, line in enumerate(loopset_lines):
        loop_file = line.strip()
        with open(loop_file, 'r') as f:
            loop_code = f.read()
        
        init_code = generate_with_retry(loop_code, loop_file, args.main_file, args.max_retries, args.base_url, args.api_key, args.model_name)
        if init_code is None:
            fail_loops.append(loop_file)
            continue
        file_name = loop_file.split('/')[-1]
        output_file_path = os.path.join(args.output_dir, f"input_{file_name}")
        with open(output_file_path, 'w') as f:
            f.write(init_code)
        loop_file = os.path.relpath(loop_file, os.getcwd())
        output_file_path = os.path.relpath(output_file_path, os.getcwd())
        loop_input_map.append({
            "codelet": loop_file,
            "input": output_file_path
        })
        success_count += 1

    with open(args.output, 'w') as f:
        json.dump(loop_input_map, f, indent=4)
    with open(args.fail_loops_file, 'w') as f:
        for loop_file in fail_loops:
            f.write(f"{loop_file}\n")
    print(f"Generation completed. Success: {success_count}, Failed: {len(fail_loops)}")
'''
python3 ../scripts/gen_input.py --main_file ../corpus/driver/main.c \
--loopset_file ./numpy_loop_files.txt \
--output_dir ./loop_input/numpy \
--output numpy_basic_corpus.json \
--fail_loops_file ./numpy_init_fail.txt \
--max_retries 5 \
--api_key sk-343c906378234d3388fc2bee552437e8 \
--base_url https://dashscope.aliyuncs.com/compatible-mode/v1 \
--model_name qwen-plus
'''