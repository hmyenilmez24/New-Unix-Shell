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


int main(int argc, char* argv[])
{
    
    char input[50];
    char *inputptr;
    
    inputptr = input;
    
    printf(">>");
    gets(inputptr);
    
        while((strcmp(inputptr, "quit")!=0)){
            
            const char s[2] = ";"; // split input according to ";"
            char *token;
            token = strtok(inputptr, s); // get the first token
            
            if (strcmp(token, "quit")==0){return 0;} // first token == quit -> quit
            
            
            pthread_t thread1, thread2;
            pthread_create(&thread1, NULL, myfunc, (void *) token);
            pthread_join(thread1,NULL);
            
            while( token != NULL )  // walk through other tokens
            {
                
                if (strcmp(token, "quit")==0){return 0;} // other tokens == quit -> quit
                
                token = strtok(NULL, s);
                pthread_create(&thread2, NULL, myfunc2, (void *) token);
                pthread_join(thread2,NULL);
                
            }
            
            printf(">>");
            gets(inputptr);
            
        }
  
    return 0;
    
}














