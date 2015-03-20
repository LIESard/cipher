#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * cipher(char * input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            continue;
        }
        int thechar = (int) input[i];

        if (thechar >= 65 && thechar <= 90) {
            thechar += 13;

            if (thechar > 90) {
                thechar -= 26;
            }
        } else if (thechar >= 97 && thechar <= 122) {
            thechar += 13;

            if (thechar > 122) {
                thechar -= 26;
            }
        }

        input[i] = (char) thechar;
    }
    return input;
}

int main(int argc, char ** argv) {
    if (argc <= 1) {
        printf("usage: cipher [message]\n");
        return 0;
    }

    char * output = malloc(sizeof(char) * 256);

    int i;
    for (i = 1; i < argc; i++) {
        output = cipher(argv[i]);
        printf("%s\n", output);
    }

    return 0;
}
