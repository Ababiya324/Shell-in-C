#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void name(){
        char* line = NULL;
        size_t len =0;
        printf("$ ");
        ssize_t read = getline(&line, &len, stdin);
        if (read!=-1){
                line[strcspn(line, "\n")]='\0';
                printf("%s@CP20:~$", line);
        }
        free(line);
}

void prse(char* response){
        char** terms=calloc(strlen(response),sizeof(char*));
        int j = 0;
        int pos = 0;  // current position in response
        int len = strlen(response);
        
        while (pos < len){
                // Skip spaces
                while (pos < len && response[pos] == ' ') {
                        pos++;
                }
                
                if (pos >= len) break;  // reached end
                
                char* term = calloc(strlen(response), sizeof(char));
                int term_idx = 0;  // position within current word
                
                // Copy characters until space or end
                while (pos < len && response[pos] != ' ') {
                        term[term_idx] = response[pos];
                        term_idx++;
                        pos++;
                }
                
                term[term_idx] = '\0';  // null terminate
                terms[j] = term;
                j++;
        }
        
        // Print the array
        for(int i = 0; i < j; i++){
                printf("arg[%d] = %s\n", i, terms[i]);
        }
}

int main(){
        name();
        char* response = NULL;
        size_t length =0;
        printf("$ ");
        ssize_t read = getline(&response, &length, stdin);
        if (read!=-1){
                response[strcspn(response, "\n")]='\0';
                prse(response);
        }
        free(response);
}
