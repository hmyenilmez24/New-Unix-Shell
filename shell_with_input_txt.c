#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/*
 Hüseyin Mert Yenilmez
 14216255208
 Operating Systems
 Project 1
 */

// works with:
// clang /Users/mac/Desktop/c_folder/hw11/hw11/shell_with_input_txt.c -o /Users/mac/Desktop/c_folder/hw11/hw11/shell_with_input_txt
// ./shell_with_input_txt.c shell /Users/mac/Desktop/input.txt

void *myfunc (void *myvar){
    
    char command[50];
    char *token;
    
    token = (char *) myvar;
    
    sprintf(command,"\"%s\"", token);
    system(token);
    
    return 0;
    
}

void *myfunc2 (void *myvar){
    
    char command[50];
    char *token;
    
    token = (char *) myvar;
    
    sprintf(command,"\"%s\"", token);
    system(token);
    
    return 0;
    
}

int main(int argc, char * argv[])
{
    
    char input[50];
    char *inputptr;
    
    inputptr = input;
    
    printf(">>");
    gets(inputptr);
    
    if(strcmp(argv[1], "shell")==0){
        
        char line[1024];
        FILE *ptr_file;
        ptr_file =fopen(argv[2],"r");
        
        if (!ptr_file){
            return 1;
        }
        
        
        if( ptr_file == NULL ) {
            printf("file is empty\n");
        }
        
        while (fgets(line,1000, ptr_file)!=NULL){
           
            const char s[2] = ";";
            char *token;
            
            token = strtok(line, s); // get the first token
            
            if(strcmp(token, "quit")!=0){
                
                pthread_t thread1, thread2;
                pthread_create(&thread1, NULL, myfunc, (void *) token);
                pthread_join(thread1,NULL);
                
                
                while( token != NULL )  // walk through other tokens
                {
                    
                    token = strtok(NULL, s);
                    pthread_create(&thread2, NULL, myfunc2, (void *) token);
                    pthread_join(thread2,NULL);
                    
                }
                
            }
            
        }
        
    }
    
    return 0;
    
}



