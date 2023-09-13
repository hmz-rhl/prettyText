#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void say(char* text){
    
    int size = sizeof(text)/text[0];
    char *buffer = calloc(size, sizeof(text));
    if(buffer == NULL){
        exit(1);
    }
    int index = 0;
    char start;

    char letter = text[index];
    while(letter != '\0'){

        if(letter >= 'a' && letter <= 'z') start = 'a';
        else if (letter >= 'A' && letter <= 'Z') start = 'A';
        else{
            buffer[index] = letter;
            printf("\r%s", buffer);
            fflush(stdout);
            index++;
            letter = text[index];
            continue;
        }
        

        for(char i = start;  i <= letter; i++){

            //printf("\r");
            buffer[index] = i;
            printf("\r%s", buffer);
            fflush(stdout);
            usleep(30000);
        }
        index++;
        letter = text[index];
        
    }
    putchar('\n');
    free(buffer);
    return;
}

int main()
{
    say("Hello World !");
    return 0;
}
