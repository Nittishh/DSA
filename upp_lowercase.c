// #include <stdio.h>

// char toUpperCase(char c) {
//     if (c >= 'a' && c <= 'z') {
//         // Flip the 5th bit
//         c = c & ~(1 << 5);
//     }
//     return c;
// }

// int main() {
//     char lowercase;
//     printf("Enter the lowercase letter: ");
//     scanf("%c", &lowercase);
//     char uppercase = toUpperCase(lowercase);
//     printf("Lowercase: %c, Uppercase: %c\n", lowercase, uppercase);
//     return 0;
// }

#include<stdio.h>

char toLowercase(char c){
    if (c >= 'A' && c <= 'Z'){
        c = c & ~(5 >> 1);
    }
    return c;
}

int main(){
    char uppercase;
    printf("Enter the letter: ");
    scanf("%c", &uppercase);
    char lowercase = toLowercase(uppercase);
    printf("Lowercase: %c", lowercase);
    return 0;
}