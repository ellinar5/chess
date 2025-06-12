#include <stdio.h>
#include <string.h>
#include "CreatingAChessBoard.h"
#include "CheckAttacks.h"
#include "SplittingShapesIntoColors.h"

int main()
{
    char input[16]; // Буфер для ввода пользователя
    char board[10][10]; // Шахматная доска
    int colors[10][10]; // Массив цветов фигур

    fillempty(board); // Инициализация пустой доски
    InitializeColors(colors); // Инициализация цветов

    LoadingShapes(board, "input.txt"); // Загрузка фигур из файла
    if (!AssignColorsToPieces(board, colors))  // Назначение цветов фигурам
    { 
        printf("Failed to assign colors.\n");
        return 1;
    }


    while (1)
    {
        printf("\n");
        printf("Enter \"start\" to start the program or \"help\" for a brief description of the program or \"exit\" to exit the program: ");
        scanf("%15s", input);

        if (strcmp(input, "start") == 0) 
        {
            DrawingBoard(board); // Отрисовка доски
            printf("\n");
            CheckAllAttacks(board, colors); // Проверка всех атак
        }
        else if (strcmp(input, "help") == 0) 
        {
            printf("Instructions:\n");
            printf("- Pieces are loaded from input.txt (max 10, min 2, no pawns).\n");
            printf("- Coordinates: x (1–8, left to right), y (1–8, bottom to top).\n");
            printf("- Supported pieces: king, queen, rook, bishop, horse, shadow.\n");
            printf("- Pieces are split into White and Black automatically.\n");
            printf("- Command 'start': shows board and all valid attacks.\n");
            printf("- Command 'exit': exits the program.\n");
        }
        else if (strcmp(input, "exit") == 0)
        {
            printf("Exiting the program.\n");
            break;
        }
        else 
        {
            printf("Unknown command. Available commands: start, help, exit.\n");
        }
    }

    return 0;
}

