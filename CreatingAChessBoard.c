#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "CreatingAChessBoard.h"

// Заполнение доски начальными значениями (рамка и пустые клетки)
void fillempty(char board[][10])
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++) 
        {
            if ((x == 0 && y == 0) || (x == 9 && y == 9) || (x == 0 && y == 9) || (x == 9 && y == 0))
            {
                board[x][y] = '#'; // Угловые клетки
            }
            else if ((x == 0 || x == 9) && y > 0 && y < 9)
            {
                board[x][y] = '0' + y; // Номера строк (левый и правый края)
            }
            else if ((y == 0 || y == 9) && x > 0 && x < 9)
            {
                board[x][y] = '0' + (9 - x); // Номера столбцов (верхний и нижний края)
            }
            else
            {
                board[x][y] = ' '; // Пустые клетки доски
            }
        }
    }
}

// Отрисовка шахматной доски с рамкой
void DrawingBoard(char board[][10])
{
    for (int x = 0; x < 10; x++) 
    {
        for (int y = 0; y < 10; y++)
        {
            printf("| %c ", board[x][y]); // Вывод символа клетки
        }
        printf("|\n"); // Завершение строки
        for (int y = 0; y < 10; y++) 
        {
            printf("|___"); // Разделитель строк
        }
        printf("|\n"); // Завершение разделителя
    }
}

// Загрузка фигур из файла на доску
void LoadingShapes(char board[][10], const char* filename)
{
    char name[16]; // Буфер для названия фигуры
    int x, y;      // Координаты фигуры
    int count = 0;  // Счётчик загруженных фигур

    // Список разрешённых фигур
    char allowedPieces[][10] = { "king", "queen", "rook", "bishop", "horse", "shadow" };
    const int numAllowed = 6; // Количество разрешённых фигур

    FILE* input = fopen(filename, "r"); 
    if (input == NULL) {
        perror("Error opening the input file"); 
        return;
    }

    // Чтение данных из файла
    while (fscanf(input, "%15s %d %d", name, &x, &y) == 3)
    {
        if (strcmp(name, "pawn") == 0) // Проверка на пешку (не разрешена)
        { 
            printf("Error: Pawns are not allowed in input.\n");
            fclose(input);
            return;
        }

        if (x < 1 || x > 8 || y < 1 || y > 8)  // Проверка координат
        {
            printf("Error: Coordinates out of bounds for figure '%s' at (%d, %d). Must be between 1 and 8.\n", name, x, y);
            fclose(input);
            return;
        }

        // Проверка, что фигура разрешена
        int isAllowed = 0;
        for (int i = 0; i < numAllowed; i++)
        {
            if (strcmp(name, allowedPieces[i]) == 0) 
            {
                isAllowed = 1;
                break;
            }
        }

        if (!isAllowed)
        {
            printf("Error: Unknown piece type '%s'. Only king, queen, rook, bishop, knight, shadow are allowed.\n", name);
            fclose(input);
            return;
        }

        // Преобразование координат для доски
        int row = 9 - y;
        int col = x;

        if (board[row][col] != ' ') // Проверка, что клетка свободна
        { 
            printf("Error: Cell (%d, %d) is already occupied.\n", x, y);
            fclose(input);
            return;
        }

        board[row][col] = toupper(name[0]); // Запись фигуры на доску (первая буква в верхнем регистре)
        count++; // Увеличение счётчика фигур
        if (count > 10)  // Проверка на максимальное количество фигур
        {
            printf("Error: Inaccurate number of shapes (max 10 allowed).\n");
            fclose(input);
            return;
        }
    }
    fclose(input); 

    if (count < 2)  // Проверка на минимальное количество фигур
    {
        printf("Error: Inaccurate number of shapes (minimum 2 required).\n");
        return;
    }
}