#include "mini_shell.h"

char** parse_input(char* input){
    size_t buffer_size = max_input;
    char** tokens = malloc(buffer_size * sizeof(char*));
    char* token = NULL;
    size_t position = 0;
    size_t token_length = 0;

    if (!tokens){
        perror("Malloc");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; input[i]; i++){
        token = &input[i]; 

        while (input[i] && input != ' '){
            token_length++;
            i++;
        }

        token[position] = malloc((token_length + 1)* sizeof(char));

        if (tokens[position]){
            perror("Malloc");
            exit(EXIT_FAILURE); 
        }
        for (size_t j = 0; j < token_length; j++){
            token[position][j] = token[j];
        }
        token[position][token_length] = '\0'; //null terminator to signal end of character string
        position++;
        token_length = 0; //reset length variable for next token
    }

    tokens[position] = NULL; //array terminated

    return tokens;
}