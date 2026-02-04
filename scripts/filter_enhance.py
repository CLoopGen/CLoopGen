import argparse
import subprocess
import os
import tempfile
import json

TIME_OUT = 30

def compile_and_run(loop_file, input_file, driver):

    with tempfile.TemporaryDirectory() as tmpdir:
        exec_file = os.path.join(tmpdir, "a.out")
        try:
            result = subprocess.run(
                ["clang", "-O3",
                loop_file, input_file, driver, "-o", exec_file, "-lm"],
                # cwd=temp_dir,
                capture_output=True,
                text=True,
                timeout=TIME_OUT
            )
            if result.returncode == 0:
                run_result = subprocess.run(
                    [exec_file],
                    cwd=tmpdir,
                    capture_output=True,
                    text=True,
                    timeout=TIME_OUT
                )
                if run_result.returncode == 0:
                    return True, ""
                else:
                    if run_result.returncode < 0:
                        import signal
                        signal_name = signal.Signals(-run_result.returncode).name
                        return False, f"Program terminated by signal: {signal_name}"
                    else:
                        return False, f"Run failed with exit code {run_result.returncode}:\n{run_result.stderr}\n{run_result.stdout}"
            else:
                return False, result.stderr + result.stdout
        except subprocess.TimeoutExpired:
            return False, "Compilation or run timed out."
        except FileNotFoundError:
            raise RuntimeError("clang not found. Please install Clang.")



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--input_loop_record", type=str, required=True, help="input loop record file")
    parser.add_argument("--output_loop_record", type=str, required=True, help="output filtered loop record file")
    parser.add_argument("--driver", type=str, help="driver")
    args = parser.parse_args()

    with open(args.input_loop_record, 'r') as infile:
        lines = infile.readlines()
    total_count = len(lines)
    loops_passed = []
    for line in lines:
        loop_file, input_file = line.strip().split(',')
        flag, msg = compile_and_run(loop_file, input_file, args.driver)
        if flag:
            loops_passed.append({"codelet": loop_file, "input": input_file})

    with open(args.output_loop_record, 'w') as outfile:
        json.dump(loops_passed, outfile, indent=4)
    print(f"Filtered loops: {len(loops_passed)}/{total_count} passed compilation and run tests.")

    