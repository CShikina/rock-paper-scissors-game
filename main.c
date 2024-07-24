#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    char choice, computer;
    int n, scoreUser=0, scoreComputer=0;
    char status[20];
    srand(time(NULL));

    do {
        system("cls");
        printf("        Rock-Paper-Scissors Game\n");
        for (int i=0; i<40; i++) printf("-");
        printf("\nUser\t\tVS\t\tComputer");
        printf("\n%c\t\t\t\t%c", choice, computer);
        printf("\n%d\t\t\t\t%d", scoreUser, scoreComputer);
        
        // Game Status
        if (scoreUser > scoreComputer) strcpy(status, "You are winning!");
        if (scoreUser < scoreComputer) strcpy(status, "You are losing");
        if (scoreUser == scoreComputer) strcpy(status, "Tied");
        printf("\n\nStatus: %s", status);

        // User choice
        printf("\n\nPlease enter r for rock, p for paper, s for scissors, and q to quit the game.\n");
        printf("Choice: ");
        scanf("%c", &choice);
        while (getchar() != '\n');

        // Computer's choice
        n = rand() % 2;
        if (n == 0) computer = 'r';
        if (n == 1) computer = 'p';
        if (n == 2) computer = 's';

        switch (choice){
            case 'r':
                if (computer == 'p') scoreComputer++;
                if (computer == 's') scoreUser++;
                break;
            case 'p':
                if (computer == 'r') scoreUser++;
                if (computer == 's') scoreComputer++;
                break;
            case 's':
                if (computer == 'p') scoreUser++;
                if (computer == 'r') scoreComputer++;
                break;
            case 'q':
                break;
            default:
                printf("\n\nInvalid input.");
        }

    } while (choice != 'q');
    printf("\nProgram terminated. Thanks for playing!");
}

