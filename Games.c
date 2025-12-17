#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int stonepc()
{
    int random = rand() % 4;
    int input,i;
    printf("\n\n----WELCOME TO STONE PAPER SCISSOR GAME----\n\n");
    for(i=0;i>=0;i++)
    {
        random = rand() % 4;
        printf("\n\nEnter your input,\n1 for stone\n2 for paper\n3 for scissor\n0 to EXIT: ");
        scanf(" %d", &input);
            if(input == random)
            {
                printf("Computer's input: %d", random);
                printf("\nDraw!!");
            }
            else if(input == 1 && random == 2)
            {
                printf("Computer's input: %d", random);
                printf("\nWinner: Computer");
            }
            else if(input == 1 && random == 3)
            {
                printf("Computer's input: %d", random);
                printf("\nWinner: You");
            }
            else if(input == 2 && random == 1)
            {
                printf("Computer's input: %d", random);
                printf("\nWinner: You");
            }
            else if(input == 2 && random == 3)
            {
                printf("Computer's input: %d", random);
                printf("\nWinner: Computer");
            }
            else if(input == 3 && random == 1)
            {
                printf("Computer's input: %d", random);
                printf("\nWinner: Computer");
            }
            else if(input == 3 && random == 2)
            {
                printf("Computer's input: %d", random);
                printf("\nWinner: You");
            }
            else if(input == 0)
            {
                break;
            }
            else
            {
                printf("\nInvalid input");
            }
    }
    printf("Thanks for playing.....");
    return 0;
}

void ttt() {
    char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int player = 1, move, i;

    for (i = 0; i < 9; i++) {
        printf("\n");
        printf(" %c | %c | %c\n", board[0], board[1], board[2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[3], board[4], board[5]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n\n", board[6], board[7], board[8]);

        printf("Enter position (1-9)\n");
        printf("Enter 0 to EXIT: ");
        scanf("%d", &move);

        // 🔴 EXIT condition
        if (move == 0) {
            printf("\nExiting Tic-Tac-Toe...\n");
            return;
        }

        move--;  // convert to index

        if (move < 0 || move > 8 || board[move] != ' ') {
            printf("Invalid move! Try again.\n");
            i--;
            continue;
        }

        board[move] = (player == 1) ? 'X' : 'O';

        // Check win
        if (
            (board[0]==board[1] && board[1]==board[2] && board[0]!=' ') ||
            (board[3]==board[4] && board[4]==board[5] && board[3]!=' ') ||
            (board[6]==board[7] && board[7]==board[8] && board[6]!=' ') ||
            (board[0]==board[3] && board[3]==board[6] && board[0]!=' ') ||
            (board[1]==board[4] && board[4]==board[7] && board[1]!=' ') ||
            (board[2]==board[5] && board[5]==board[8] && board[2]!=' ') ||
            (board[0]==board[4] && board[4]==board[8] && board[0]!=' ') ||
            (board[2]==board[4] && board[4]==board[6] && board[2]!=' ')
           ) {
            printf("\nPlayer %d wins! 🎉\n", player);
            return;
        }

        player = (player == 1) ? 2 : 1;
    }

    printf("\nIt's a draw! 🤝\n");
}

int numguess()
{
    srand(time(0));
    int r = rand() % 101;
    int g;
    int count = 0;
    printf("\n\n----WELCOME TO NUMBER GUESSING GAME----\n\n");
    printf("Enter -1 to exit\n");
    printf("Please enter your guess number(0-100): ");
    scanf("%d", &g);
    count++;
    while(r!=g)
    {
    if(g == -1)
    {
        break;
    }
    else if(r<g)
    {
        printf("\nMy number is less than your guess.");
        printf("\nTry again!!\n");
        count++;
    }
    else if(r>g)
    {
        printf("\nMy number is greater than your guess.");
        printf("\nTry again!!\n");
        count++;
    }
    printf("\nPlease enter your guess number: ");
    scanf("%d", &g);
    }
    if(g!=-1)
    {
    printf("\nYour guess is correct, you won.");
        printf("\nYou took %d attempts to guess the number.\n", count);
    }

    printf("\nTHANKS FOR PLAYING....\n");
    return 0;
}

int main() 
{
    char n;
    label:
    printf("Enter the game you want to play:-\n");
    printf("\nPress 1 for number guess game.");
    printf("\nPress 2 for tic-tac-toe game.");
    printf("\nPress 3 for rock-paper-scissor game.");
    printf("\nEnter 4 to EXIT!!");
    printf("\nEnter your input: ");
    scanf(" %c", &n);
    while(n=='1' || n=='2' || n=='3' || n=='4')
    {
    switch(n)
    {
        case '1':
                numguess();
                break;
        case '2':
                ttt();
                break;
        case '3':
                stonepc();
                break;
        case '4':
                exit(0);
    }
    break;
    }
    printf("\nPlease enter a valid input\n\n");
    goto label;
}