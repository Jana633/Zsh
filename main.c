#include <stdio.h>
#include "mini_shell.h"
// TODO: Shell lifecycle
//  - initialize shell state
//  - main REPL loop
//  - graceful exit handling

// TODO: Input handling
//  - read input (getline)
//  - handle EOF (Ctrl+D)
//  - ignore empty / whitespace-only input

// TODO: Lexer / Parser
//  - split input into tokens
//  - handle quotes and escapes
//  - build argv-style command structures

// TODO: Built-in commands
//  - cd
//  - pwd
//  - echo
//  - env
//  - setenv / unsetenv
//  - which
//  - exit

// TODO: External commands
//  - fork / execve
//  - PATH resolution
//  - wait for child processes

// TODO: Environment variables
//  - copy envp into internal structure
//  - variable expansion ($VAR, $?)

// TODO: Redirections
//  - input (<)
//  - output (>)
//  - append (>>)

// TODO: Pipes
//  - create pipelines with |
//  - manage file descriptors

// TODO: Job control
//  - background execution (&)
//  - job list
//  - fg / bg

// TODO: Signals
//  - SIGINT (Ctrl+C)
//  - SIGQUIT
//  - SIGTSTP

// TODO: Exit status tracking
//  - store last command status ($?)

// TODO: Error handling
//  - command not found
//  - permission denied
//  - syntax errors

// TODO: Memory management
//  - free all resources per loop
//  - avoid leaks in long-running shell

void shell_loop(char** env){
    char* input = NULL;
    size_t input_size = 0;
    char** args;
    while (1) {
        printf("[mini_shell]> ");
        if (getline(&input, &input_size, stdin) == -1){
            perror("getline");
            break;
        }

       
        args = parse_input(input);

        if (args[0]== NULL) {
            shell_builts(args, env, initial_director);
        }

    }
}
int main (int argc, char** argv, char** env){
    (void)argc;
    (void)argv;

    shell_loop(env);

    return 0;
}