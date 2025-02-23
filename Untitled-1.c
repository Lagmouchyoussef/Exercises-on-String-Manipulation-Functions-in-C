#include <stdio.h>
#include <string.h>

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

char at(char text[], int i) {
    if (i < 0 || i >= stringLength(text)) return '\0';
    return text[i];
}

void concatenate(char ch1[], char ch2[]) {
    if (stringLength(ch1) + stringLength(ch2) >= 100) {
        printf("Concatenation not possible.\n");
        return;
    }
    strcat(ch1, ch2);
}

int countDigits(char ch[]) {
    int count = 0;
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] >= '0' && ch[i] <= '9') count++;
    }
    return count;
}

int firstSpaceIndex(char ch[]) {
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] == ' ') return i;
    }
    return -1;
}

void printWords(char ch[]) {
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] == ' ') printf("\n");
        else printf("%c", ch[i]);
    }
    printf("\n");
}

void removeNewline(char str[]) {
    int len = stringLength(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    char ch1[100], ch2[100];
    int choice, index;
    printf("1. String Length\n2. Character at Index\n3. Concatenate Strings\n4. Count Digits\n5. First Space Index\n6. Print Words\nEnter choice: ");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
        case 1:
            printf("Enter string: ");
            fgets(ch1, 100, stdin);
            removeNewline(ch1);
            printf("Length: %d\n", stringLength(ch1));
            break;
        case 2:
            printf("Enter string: ");
            fgets(ch1, 100, stdin);
            removeNewline(ch1);
            printf("Enter index: ");
            scanf("%d", &index);
            printf("Character: %c\n", at(ch1, index));
            break;
        case 3:
            printf("Enter first string: ");
            fgets(ch1, 100, stdin);
            removeNewline(ch1);
            printf("Enter second string: ");
            fgets(ch2, 100, stdin);
            removeNewline(ch2);
            concatenate(ch1, ch2);
            printf("Result: %s\n", ch1);
            break;
        case 4:
            printf("Enter string: ");
            fgets(ch1, 100, stdin);
            removeNewline(ch1);
            printf("Digits: %d\n", countDigits(ch1));
            break;
        case 5:
            printf("Enter string: ");
            fgets(ch1, 100, stdin);
            removeNewline(ch1);
            printf("First space index: %d\n", firstSpaceIndex(ch1));
            break;
        case 6:
            printf("Enter string: ");
            fgets(ch1, 100, stdin);
            removeNewline(ch1);
            printWords(ch1);
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}