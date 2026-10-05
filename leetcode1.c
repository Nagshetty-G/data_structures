#include <stdio.h>

void reverse_prefix(char word[], char ch){
    int top = -1;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == ch) {
            top = i;
            break;
        }
    }
    if (top == -1) {
        return;
    }
    int start = 0;
    int end = top;
    while (start < end) {
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
}

int main(){
    char word[100];
    char ch;
    printf("Enter a word: ");
    scanf("%99s", word);
    printf("Enter the character to find: ");
    scanf(" %c", &ch);
    reverse_prefix(word, ch);
    printf("Result: %s\n", word);
    return 0;
}
