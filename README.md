# c-exercises

C programming exercises (algorithms and data structures), organized by topic.

## Directory Structure

```
c-exercises/
├── Arrays/
│   └── Two-Dimensional/
│       ├── min_path_sum/
│       └── queen_attack/
├── Number-Theory/
│   └── sum_sum_sum/
├── .gitignore
├── README.md
└── run.sh
```

Each problem has its own folder with `main.c` (solution) and `input.txt` (sample input).

## Build and Run

Requires GCC and a bash shell (Linux, macOS, or WSL on Windows).

```bash
chmod +x run.sh                     # only needed once
./run.sh <path-to-problem>          # uses input.txt if it exists, otherwise reads from the keyboard
./run.sh <path-to-problem> --manual # reads from the keyboard
```

On Windows, run the same commands inside a WSL terminal, or prefix each one with `wsl` when using PowerShell/CMD.


## Problems

### Arrays

#### Two-Dimensional

| # | Problem | Time | Space | Code |
|---|---------|------|-------|------|
| 1 | Min path sum | O(m·n) | O(m·n) | [main.c](Arrays/Two-Dimensional/min_path_sum/main.c) |
| 2 | Queens attack | O(N²) | O(N²) | [main.c](Arrays/Two-Dimensional/queen_attack/main.c) |

### Number Theory

| # | Problem | Time | Space | Code |
|---|---------|------|-------|------|
| 1 | Sum sum sum | O(√n) | O(1) | [main.c](Number-Theory/sum_sum_sum/main.c) |