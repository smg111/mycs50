#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (void) {
    string s = get_string();
    if (s != NULL){
        int k = 0;
        // Avoid trying to access memory that isn't there
        while(k <= strlen(s)-1){
            // Skip white space before first name
            while (s[k] == ' '){
            k++;
        }
        // Print first initial
        printf("%c",toupper(s[k]));

        // Get index of last letter of first word
        while (s[k+1] != ' ' && k <= strlen(s)-1){
            k++;
        }

        // Get index of second initial, if there is one
        while (s[k+1] == ' ' && k <= strlen(s)-1){
            k++;
        }
        // Prints second initial, if there is one
        if (k+2 != strlen(s) && s[k+1] != '\0'){
        printf("%c",toupper(s[k+1]));
        }

        // Get index of last letter of second word
        while (s[k+1] != ' ' && k <= strlen(s)-1){
            k++;
        }

        // Get index of third initial
        while (s[k+1] == ' ' && k <= strlen(s)-1){
            k++;
        }
        // Prints third initial, if there is one
        if (k+2 != strlen(s) && s[k+1] != '\0'){
            printf("%c",toupper(s[k+1]));
        }

        // Get index of last letter of third word to avoid repeating last initial
        while (s[k+1] != ' ' && k <= strlen(s)-1){
            k++;
        }
    }
    printf("\n");
    }
    else {
        printf("Nothing entered!\n");
    }
        }
