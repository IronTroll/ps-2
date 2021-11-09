#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}



void get_available_letters(const char letters_guessed[], char available_letters[])
{
    int k = 0;
    for (char c = 'a'; c <= 'z'; c++){
        int p = 0;
        for(int i=0;i<strlen(letters_guessed);i++){
            if(c==letters_guessed[i]){
                p = 1;
                break;
            }
        }
        if(!p){
            available_letters[k] = c;
            k++;
        }            
    }
    available_letters[k] = '\0';


    //printf("\n%s\n ahoj\n",available_letters);
    
    
   /* 
    available_letters = "abcdefghijklmnopqrstuvwxyz";
    //printf("%s\n", available_letters);
    printf("%s\n", available_letters);
    available_letters[3] = '_';
    printf("%s\n", available_letters);
    
    for (int c=1;c<=26;c++){
        available_letters[c] = available_letters[1];
        printf("%s\n", available_letters);
        c++;
    }
    printf("%s\n", available_letters); 
    /*
    for (int i = 0; i < strlen(letters_guessed); i++){
        for (int k = 0; k < strlen(available_letters); k++){
            
            if (letters_guessed[i] == available_letters[k]){
                
            }
        }
    }
    */      
}
void input_char(char letters_guessed[], char vstup){
    if(strlen(letters_guessed)==0)
        letters_guessed[0] = vstup;
    else{
        int pom = 0;
        int i = 0;
        for(i=0;i<strlen(letters_guessed);i++){
            if(vstup == letters_guessed[i])
                pom=1;
        }
        if(!pom)
            letters_guessed[i] = vstup;
    }
}

int check_char(char secret[], vstup){
    for(i=0;i<strlen(secret);i++){
            if(vstup == letters_guessed[i])
                return 1;
        }
    return 0;
}

void hangman(const char secret[]){
    printf("\nWelcome to the game, Hangman!");
    printf("\nI am thinking of a word that is %d letters long.",strlen(secret));
    int try = 8;
    char result[30];
    char vstup[30];
    char letters_guessed[26];
    char secret[15];
    
    while(1){
        printf("\n-------------");
        if(is_word_guessed(secret, letters_guessed)){
            printf("Congratulations, you won!");
            break;
        }
        if(try==0){
            printf("Sorry, you ran out of guesses. The word was %s",secret);
        }
        printf("\nYou have %d guesses left.",try);
        get_available_letters(vstup, result);          //dorobit zostatok pismen
        printf("\nAvailable letters: %s", result);
        printf("\nPlease guess a letter: ");
        scanf("%s",&vstup);
        vstup = tolower(vstup);

        input_char(letters_guesssed, vstup);

        if(strlen(vstup)==1)
        {
            get_guessed_word(secret, letters_guessed, result);
            
            if(isalpha(vstup)==2){
                printf("Oops! '@' is not a valid letter: %s", result);
            }
            else{
                if(check_char(secret,vstup)){
                printf("\nGood guess: %s",result);

                }
                else{
                    printf("Oops! That letter is not in my word: %s",result);
                    try--;
                }   
            }
        }
        else if(strlen(vstup)>1){
            letters_guessed = vstup;
            if(is_word_guessed(secret, letters_guessed))
                printf("\nGood guess: %s",result);
            else 
                printf("Sorry, bad guess. The word was %s",secret);
        }
    }
}




int main()
{
  char slovo[15]="dejepis";
  get_word(slovo);

  printf();  
    //main main
    printf("Welcome to the game, Hangman!\n");

}


/*
int main(){
    char result[30] = "abcdefghijklmnopqrstuvwxyz";
    printf("%s\n", result);
    int k = 26;
    for (int c=4;c<=strlen(result);c++){
        result[c] = result[c--];
        printf("%s\n", result);
        c++;
    } 

}
*/

















void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    int i = 0;
    for(i=0;i<strlen(secret);i++){
        if(strlen(letters_guessed)==0){
            gues][i]=='_';
            continue;
        }

        for(int k=0;k<strlen(letters_guessed);k++){
            if(secret[i]==letters_guessed[k]){
                guessed_word[i] = secret[i];
                break;
            }
            else
              guessed_word[i] = '_';
        }
    }
    guessed_word[i] = '\0';
}



void hangman(const char secret[]){
    printf("\nWelcome to the game, Hangman!");
    printf("\nI am thinking of a word that is %lu letters long.",strlen(secret));
    int try = 8;
    char result[30];
    char vstup[20];
    char letters_guessed[26];
    //char secret[15];

    while(1){
        printf("\n-------------");
        if(is_word_guessed(secret, letters_guessed)){
            printf("Congratulations, you won!");
            break;
        }
        if(try==0){
            printf("Sorry, you ran out of guesses. The word was %s",secret);
        }
        printf("\nYou have %d guesses left.",try);
        get_available_letters(vstup, result);          //dorobit zostatok pismen
        printf("\nAvailable letters: %s", result);
        printf("\nPlease guess a letter: ");
        scanf("%s",vstup);
        //vstup = tolower(vstup);
        //
//        make_lower(vstup);

        for(int i=0;i<strlen(vstup);i++){
            vstup[i] = tolower(vstup[i]);
        }


        //input_char(letters_guessed, vstup);

        ////////pokus////////////////////////////////
        if(strlen(letters_guessed)==0)
            letters_guessed[0] = vstup[0];
        else{
            int pom = 0;
            int i = 0;
            for(i=0;i<strlen(letters_guessed);i++){
                if(vstup[0] == letters_guessed[i])
                    pom=1;
            }
        if(!pom)
                letters_guessed[i] = vstup[0];
        }
        /////////////////////////////////////////////////////////////////

        if(strlen(vstup)==1){
            get_guessed_word(secret, letters_guessed, result);

            if(isalpha(vstup)==2){
                printf("Oops! %c is not a valid letter: ",vstup);
                for(int i = 0;i<strlen(result);i++){
                    printf("%c",result[i]);
                    if(i!=(strlen(result)-1))
                        printf(" ");
                }
            }
            else{
                if(check_char(secret,vstup)){
                printf("\nGood guess: %s",result);

                }
                else{
                    printf("Oops! That letter is not in my word: ");
                    for(int i = 0;i<strlen(result);i++){
                        printf("%c",result[i]);
                        if(i!=(strlen(result)-1))
                            printf(" ");
                    }
                    try--;
                }
            }
        }
        else if(strlen(vstup)>1){
            //letters_guessed = vstup;
            if(is_word_guessed(secret, vstup))
                printf("\nGood guess: %s",result);
            else
                printf("Sorry, bad guess. The word was %s",secret);
        }
    }
}


















