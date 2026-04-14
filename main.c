// Project: Advanced Hangman Game (Ultimate Final Version)
// Author: Your Name

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

#define MAX_WORDS 30

char *words[MAX_WORDS] = {
"superposition","entanglement","wavefunction","eigenvalue","eigenvector",
"decoherence","uncertainty","quantization","interference","tunneling",
"modulation","demodulation","bandwidth","sampling","aliasing",
"convolution","correlation","transform","fourier","laplace",
"filtering","amplification","attenuation","synchronization",
"multiplexing","orthogonality","stochastic","probability",
"transmission","dispersion"
};

char *clues[MAX_WORDS][6] = {
{"Exists in many possibilities","Not fixed until observed","State is undefined","Quantum combination","Multiple states","System in many states simultaneously"},
{"Linked beyond distance","Connection without medium","Instant relation","Quantum link","Particles affect each other","Strong quantum correlation"},
{"Defines probability","Not a definite value","Changes on observation","Quantum state","Describes system","Function of quantum system"},
{"Scalar in equations","Value from transformation","Related to matrix","Linear algebra term","Associated with vector","Special value of matrix"},
{"Direction with scaling","Vector property","Transformation related","Linear algebra concept","Paired with eigenvalue","Vector in transformation"},
{"Loss of quantum nature","Becomes classical","System disturbance","Quantum decay","Loss of coherence","Breakdown of quantum state"},
{"Cannot measure exactly","Limits accuracy","Observation changes result","Quantum limitation","Precision boundary","Uncertainty principle"},
{"Discrete levels","Not continuous","Energy packets","Quantum behavior","Level separation","Discrete energy values"},
{"Wave mixing","Adds or cancels","Pattern formation","Wave interaction","Signal overlap","Constructive/destructive waves"},
{"Pass through barrier","Impossible classically","Quantum trick","Particle crossing","Barrier penetration","Quantum tunneling"},
{"Signal change","Before sending","Altering waveform","Communication process","Signal encoding","Encoding information"},
{"Reverse of encoding","Signal recovery","Extract data","Communication step","Decode signal","Decoding information"},
{"Frequency range","Signal width","Capacity limit","Transmission property","Signal spread","Range of frequencies"},
{"Discrete conversion","Continuous to digital","Sampling process","Signal conversion","Time domain process","Sampling technique"},
{"Distortion effect","Wrong sampling","Overlap signals","Signal issue","Frequency mix","Aliasing error"},
{"Signal combination","Time shift overlap","Integration process","Mathematical tool","System output","Signal convolution"},
{"Signal similarity","Matching signals","Compare waves","Analysis tool","Signal comparison","Correlation measure"},
{"Change domain","Time to frequency","Signal mapping","Math tool","Signal analysis","Domain transformation"},
{"Frequency analysis","Series expansion","Wave breakdown","Math technique","Signal analysis","Fourier transform"},
{"System analysis","Differential solving","Math domain","Control tool","Engineering method","Laplace transform"},
{"Remove noise","Clean signal","Selective passing","Signal process","Filter use","Signal filtering"},
{"Increase strength","Boost signal","Enhance power","Amplifier action","Signal gain","Amplification"},
{"Reduce strength","Loss of power","Signal fading","Decrease level","Weak signal","Attenuation"},
{"Time alignment","Match signals","Synchronize","Coordination","Timing control","Signal synchronization"},
{"Combine channels","Multiple signals","Sharing medium","Communication method","Signal merging","Multiplexing"},
{"Independent signals","No interference","Separate axes","Math property","Signal independence","Orthogonality"},
{"Random nature","Uncertain system","Probabilistic","Statistical model","Random process","Stochastic system"},
{"Chance measure","Likelihood value","Probability concept","Math term","Event chance","Probability"},
{"Send data","Transfer signal","Communication","Move information","Signal travel","Transmission"},
{"Spread in medium","Signal distortion","Delay effect","Wave spreading","Medium effect","Dispersion"}
};

int isClose(char ch, char word[]) {
    for(int i=0; word[i]!='\0'; i++) {
        if(abs(word[i]-ch)==1) return 1;
    }
    return 0;
}

void revealLetter(char word[], char guessed[], int *correct) {
    int len = strlen(word);
    while(1) {
        int r = rand()%len;
        if(guessed[r]=='_') {
            guessed[r] = word[r];
            (*correct)++;
            break;
        }
    }
}

int main() {
    srand(time(0));
    char playAgain='y';

    while(playAgain=='y') {

        int index = rand()%MAX_WORDS;
        char word[30], guessed[30];
        strcpy(word, words[index]);

        int len=strlen(word);
        int attempts=6, correct=0, score=100;
        int used[26]={0};

        for(int i=0;i<len;i++) guessed[i]='_';
        guessed[len]='\0';

        printf(CYAN "\n🎮 Advanced Hangman Game 🎮\n" RESET);
        printf("The word contains %d letters.\n", len);

        int clueLevel=0;

        while(attempts>0) {

            printf("\nWord: ");
            for(int i=0;i<len;i++) printf("%c ", guessed[i]);

            printf("\nAttempts: %d | Score: %d\n", attempts, score);

            if(clueLevel<5)
                printf("Clue: %s\n", clues[index][clueLevel]);
            else
                printf("Final clue available! Press '?' to unlock (-50 points)\n");

            if((6 - attempts) >= 2)
                printf("You may guess the full word.\n");

            printf("Enter input (letter / word / '!' / '?'): ");

            char input[30];
            scanf("%s", input);

            // FULL WORD GUESS
            if(strlen(input) > 1) {
                if((6 - attempts) < 2) {
                    printf(RED "You can guess the full word only after the 3rd attempt.\n" RESET);
                    continue;
                }

                if(strcmp(input, word)==0) {
                    printf(GREEN "\n🎉 Congratulations! You guessed it correctly.\n" RESET);
                    printf("Final Score: %d\n", score + 20);
                    break;
                } else {
                    printf(RED "Incorrect word guess!\n" RESET);
                    attempts--;
                    score -= 15;
                    continue;
                }
            }

            char ch = tolower(input[0]);

            if(ch=='?' && clueLevel>=5) {
                if(score>=50) {
                    score-=50;
                    printf(YELLOW "Final Clue: %s\n" RESET, clues[index][5]);
                } else {
                    printf(RED "Not enough score!\n" RESET);
                }
                continue;
            }

            if(ch=='!') {
                if(score>=20) {
                    revealLetter(word, guessed, &correct);
                    score-=20;
                    printf(YELLOW "A letter has been revealed (-20 points).\n" RESET);
                } else {
                    printf(RED "Not enough score!\n" RESET);
                }
                continue;
            }

            if(used[ch-'a']) {
                printf(YELLOW "Already guessed!\n" RESET);
                continue;
            }
            used[ch-'a']=1;

            int found=0;

            for(int i=0;i<len;i++) {
                if(word[i]==ch && guessed[i]=='_') {
                    guessed[i]=ch;
                    correct++;
                    found=1;
                }
            }

            if(found)
                printf(GREEN "Correct guess. Keep going!\n" RESET);
            else if(isClose(ch,word)) {
                printf(YELLOW "Close guess.\n" RESET);
                attempts--; score-=5;
            } else {
                printf(RED "Incorrect guess.\n" RESET);
                attempts--; score-=10;
            }

            clueLevel++;

            if(correct==len) {
                printf(GREEN "\n🎉 Congratulations! You guessed it correctly.\n" RESET);
                printf("Final Score: %d\n", score);
                break;
            }
        }

        // 🔥 FINAL LOSS DISPLAY (YOUR FEATURE)
        if(attempts==0) {

            char upperWord[30];
            strcpy(upperWord, word);

            for(int i=0; upperWord[i]!='\0'; i++)
                upperWord[i] = toupper(upperWord[i]);

            printf(RED "\n😢 You have used all attempts.\n" RESET);

            printf(GREEN "\n====================================\n");
            printf("   THE WORD WAS:  %s\n", upperWord);
            printf("====================================\n" RESET);
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c",&playAgain);
    }

    printf(CYAN "\nSee you again!\n" RESET);
    return 0;
}