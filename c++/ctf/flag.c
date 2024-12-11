#include <stdio.h>
#include <stdlib.h>

void win(int secret) {
    if (secret == 0xdeadbeef) {
        FILE *file;
        char flag[100];

        file = fopen("flag.txt", "r");
        if (file == NULL) {
            printf("Failed to open the flag file.\n");
            exit(1);
        }

        fgets(flag, sizeof(flag), file);
        printf("Congratulations! Here's your flag: %s\n", flag);
        fclose(file);
    } else {
        printf("Try again!\n");
        exit(0);
    }
}

void vulnerable_function() {
    char buffer[64];
    gets(buffer);
}
int main() {
    printf("Enter some text: ");
    fflush(stdout);
    vulnerable_function();
    printf("Exiting...\n");
    return 0;
}