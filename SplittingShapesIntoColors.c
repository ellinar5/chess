#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "SplittingShapesIntoColors.h"

// Инициализация массива цветов (все клетки -1)
void InitializeColors(int colors[][10]) 
{
    for (int y = 0; y < 10; y++) 
    {
        for (int x = 0; x < 10; x++) 
        {
            colors[y][x] = -1; // -1 означает отсутствие фигуры
        }
    }
}

// Назначение цветов фигурам (белые или чёрные)
int AssignColorsToPieces(char board[][10], int colors[][10]) 
{
    int count = 0; // Счётчик фигур
    int coords[64][2]; // Массив координат фигур

    // Сбор координат всех фигур на доске
    for (int y = 1; y <= 8; y++)
    {
        for (int x = 1; x <= 8; x++) 
        {
            if (isupper(board[y][x]))  // Если клетка содержит фигуру
            {
                coords[count][0] = x; // Сохранение координаты X
                coords[count][1] = y; // Сохранение координаты Y
                count++; // Увеличение счётчика
            }
        }
    }

    if (count < 2)  // Проверка на минимальное количество фигур
    {
        printf("Error: Not enough pieces (min 2 required).\n");
        return 0;
    }

    int white = 1, black = 0; // Белые и чёрные

    // Назначение цветов фигурам
    for (int i = 0; i < count; i++) 
    {
        int x = coords[i][0];
        int y = coords[i][1];

        if (count % 2 == 0)  // Чётное количество фигур
        {
            colors[y][x] = (i < count / 2) ? white : black; // Первая половина - белые, вторая - чёрные
        }
        else  // Нечётное количество фигур
        {
            if (i == 0) colors[y][x] = white; // Первая фигура - белая
            else if (i == count - 1) colors[y][x] = black; // Последняя фигура - чёрная
            else colors[y][x] = (i % 2 == 0) ? white : black; // Чередование цветов
        }
    }

    return 1; // Успешное завершение
}

// Проверка, могут ли фигуры атаковать друг друга (разные цвета)
bool CanAttack(int colors[][10], int x1, int y1, int x2, int y2)
{
    return colors[y1][x1] != colors[y2][x2]; // Атака возможна, если цвета разные
}

