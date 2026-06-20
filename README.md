# 🔁 Pipex

> *"This project is about handling pipes."*

A project from [42 School](https://42.fr) that reproduces the behavior of the shell pipe mechanism in C, using `fork`, `execve`, and `pipe`.

---

## 📚 About

**Pipex** mimics the behavior of the following shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

It opens two files, executes two commands, and pipes the output of the first into the input of the second — all in C, using low-level Unix system calls.

---

## 🚀 Usage

### Compilation

```bash
make
```

### Run

```bash
./pipex file1 cmd1 cmd2 file2
```

This is equivalent to:

```bash
< file1 cmd1 | cmd2 > file2
```

### Examples

```bash
./pipex infile "cat" "wc -l" outfile
# equivalent to: < infile cat | wc -l > outfile

./pipex infile "grep hello" "wc -w" outfile
# equivalent to: < infile grep hello | wc -w > outfile

./pipex infile "ls -la" "head -5" outfile
# equivalent to: < infile ls -la | head -5 > outfile
```

---

## ⚙️ How It Works

### Overview

```
file1 ──► [child 1: cmd1] ──pipe──► [child 2: cmd2] ──► file2
```

### Step by step

1. Open `file1` for reading (stdin of cmd1)
2. Open `file2` for writing (stdout of cmd2)
3. Create a `pipe()` — two file descriptors: `pipe[0]` (read end) and `pipe[1]` (write end)
4. **Fork** a first child process:
   - Redirect `stdin` → `file1` via `dup2`
   - Redirect `stdout` → `pipe[1]` via `dup2`
   - Close unused fds, then `execve(cmd1)`
5. **Fork** a second child process:
   - Redirect `stdin` → `pipe[0]` via `dup2`
   - Redirect `stdout` → `file2` via `dup2`
   - Close unused fds, then `execve(cmd2)`
6. Parent closes all pipe fds and **waits** for both children

### Key system calls

| Call | Role |
|---|---|
| `pipe(int fd[2])` | Creates a unidirectional communication channel |
| `fork()` | Creates a child process |
| `dup2(old, new)` | Redirects a file descriptor |
| `execve(path, argv, envp)` | Replaces the process with a new program |
| `waitpid()` | Waits for a child process to finish |
| `access()` | Checks if a file/command exists and is executable |

---

## 🗺️ PATH Resolution

Commands like `"grep"` or `"wc -l"` must be resolved to their full path (e.g. `/usr/bin/grep`).

```c
// Split PATH from envp
// Try each directory: /usr/bin/grep, /bin/grep, etc.
// Return the first one where access(path, X_OK) succeeds
```

If the command is not found, print an error and exit accordingly.

---

## 🛡️ Error Handling

| Error | Behavior |
|---|---|
| Wrong number of arguments | Print usage and exit |
| `file1` not found / unreadable | `perror` + exit |
| `file2` not writable | `perror` + exit |
| Command not found | `perror("command not found")` + exit child |
| `fork` / `pipe` failure | `perror` + exit |

> All open file descriptors must be closed and all allocated memory freed before exiting.

---

## 📦 Bonus — Multiple Pipes & Here Doc

### Multiple pipes

```bash
./pipex file1 cmd1 cmd2 cmd3 ... cmdN file2
```

Equivalent to:

```bash
< file1 cmd1 | cmd2 | cmd3 | ... | cmdN > file2
```

Each additional command gets its own `fork` + `pipe`, chained together.

### Here Doc

```bash
./pipex here_doc LIMITER cmd1 cmd2 file
```

Equivalent to:

```bash
cmd1 << LIMITER | cmd2 >> file
```

- Reads from `stdin` line by line until `LIMITER` is encountered
- Output is **appended** to `file` (not truncated)

```bash
./pipex here_doc END "cat" "wc -l" outfile
> hello
> world
> END
# appends "2" to outfile
```

---

## ✅ Testing

```bash
# Basic test
./pipex /etc/passwd "cat" "wc -l" outfile
< /etc/passwd cat | wc -l   # compare outputs

# Invalid command
./pipex infile "invalidcmd" "wc" outfile

# Invalid input file
./pipex nofile "cat" "wc" outfile

# Compare with shell behavior
diff <(./pipex infile "grep a" "wc -w" outfile && cat outfile) \
     <(< infile grep a | wc -w)
```

---

## 👤 Author

| Name | GitHub |
|------|--------|
| Your Name | [@Maxou911](https://github.com/Maxou911) |

---

## 📝 License

This project is part of the 42 School curriculum and is for educational purposes only.
