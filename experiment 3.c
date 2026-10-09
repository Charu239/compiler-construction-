#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[100];
    int i = 0;

    printf("Enter an expression: ");
    fgets(s, sizeof(s), stdin);

    while (s[i] != '\0') {
        if (isspace((unsigned char)s[i])) {
            i++;
        }
        else if (isalpha((unsigned char)s[i])) {
            char word[50];
            int j = 0;

            while (isalnum((unsigned char)s[i])) {
                word[j++] = s[i++];
            }
            word[j] = '\0';

            if (strcmp(word, "int") == 0 ||
                strcmp(word, "float") == 0 ||
                strcmp(word, "if") == 0 ||
                strcmp(word, "else") == 0)
                printf("%s : Keyword\n", word);
            else
                printf("%s : Identifier\n", word);
        }
        else if (isdigit((unsigned char)s[i])) {
            while (isdigit((unsigned char)s[i]))
                putchar(s[i++]);
            printf(" : Number\n");
        }
        else {
            printf("%c : Operator/Symbol\n", s[i]);
            i++;
        }
    }

    return 0;
}
