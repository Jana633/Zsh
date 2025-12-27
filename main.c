#include <stdio.h>
#include "mini_shell.h"
//TODO shell loop
//TODO input parsing
//TODO commands (the built-ins) cd, pwd, echo, env, setenv, unsetenv, which, exit
//TODO external commands
//TODO external variables
//TODO path managing
//TODO error handling

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