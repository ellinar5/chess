#include <stdio.h>
#include <ctype.h>
#include "CheckAttacks.h"
#include "SplittingShapesIntoColors.h"

// Проверка, свободен ли путь между двумя точками на шахматной доске
bool IsPathClear(char board[][10], int x1, int y1, int x2, int y2) 
{
    int dx = (x2 > x1) - (x2 < x1); // Определение направления по X (-1, 0, 1)
    int dy = (y2 > y1) - (y2 < y1); // Определение направления по Y (-1, 0, 1)
    x1 += dx; // Переход к следующей клетке по X
    y1 += dy; // Переход к следующей клетке по Y
    while (x1 != x2 || y1 != y2)  // Пока не достигнута конечная точка
    {
        if (board[y1][x1] != ' ')
        {
            return false; // Если клетка не пуста, путь заблокирован
        }
        x1 += dx; // Переход к следующей клетке по X
        y1 += dy; // Переход к следующей клетке по Y
    }
    return true; // Путь свободен
}

// Получение названия фигуры по её символу
const char* GetPieceName(char c)
{
    switch (c) 
    {
    case 'K': return "King";   // Король
    case 'Q': return "Queen";  // Ферзь
    case 'R': return "Rook";   // Ладья
    case 'B': return "Bishop"; // Слон
    case 'H': return "Horse";  // Конь
    case 'S': return "Shadow"; // Тень
    default: return "Unknown"; // Неизвестная фигура
    }
}

// Проверка, может ли фигура атаковать другую фигуру
bool DoesPieceAttack(char board[][10], int colors[][10], int x1, int y1, int x2, int y2)
{
    char attacker = board[y1][x1]; // Символ атакующей фигуры
    int dx = x2 - x1;             // Разница по X
    int dy = y2 - y1;             // Разница по Y
    int absDx = dx < 0 ? -dx : dx; // Абсолютное значение разницы по X
    int absDy = dy < 0 ? -dy : dy; // Абсолютное значение разницы по Y

    if (!CanAttack(colors, x1, y1, x2, y2)) return false; // Проверка, что фигуры разных цветов

    switch (attacker)
    {
    case 'K': // Король: атакует на расстояние 1 клетки в любом направлении
        return absDx <= 1 && absDy <= 1;
    case 'Q': // Ферзь: атакует по прямой или диагонали, если путь свободен
        return ((x1 == x2 || y1 == y2 || absDx == absDy) && IsPathClear(board, x1, y1, x2, y2));
    case 'R': // Ладья: атакует по прямой, если путь свободен
        return ((x1 == x2 || y1 == y2) && IsPathClear(board, x1, y1, x2, y2));
    case 'B': // Слон: атакует по диагонали, если путь свободен
        return (absDx == absDy && IsPathClear(board, x1, y1, x2, y2));
    case 'H': // Конь: атакует буквой "Г" (2x1 или 1x2)
        return (absDx == 2 && absDy == 1) || (absDx == 1 && absDy == 2);
    case 'S': // Тень: атакует как ферзь, но с дополнительными правилами (если путь свободен)
        return ((x1 == x2 || y1 == y2 || absDx == absDy) && IsPathClear(board, x1, y1, x2, y2));
    default:
        return false; // Неизвестная фигура не атакует
    }
}

// Печать списка фигур для одной стороны (белых или чёрных)
void PrintSidePieces(char board[][10], int colors[][10], int side)
{
    printf("%s:", side == 1 ? "White" : "Black"); // Вывод названия стороны
    int first = 1; // Флаг для обработки первой фигуры (чтобы не ставить лишнюю запятую)
    for (int y = 1; y <= 8; y++)
    {
        for (int x = 1; x <= 8; x++) 
        {
            if (board[y][x] != ' ' && isupper(board[y][x]) && colors[y][x] == side)
            {
                if (!first) printf(","); // Запятая перед всеми, кроме первой фигуры
                printf("  %s at (%d,%d)", GetPieceName(board[y][x]), x, 9 - y); // Вывод информации о фигуре
                first = 0; // Сброс флага первой фигуры
            }
        }
    }
    printf(".\n\n"); // Завершение вывода
}

// Основная функция проверки всех возможных атак на доске
void CheckAllAttacks(char board[][10], int colors[][10])
{
    PrintSidePieces(board, colors, 1); // Печать белых фигур
    PrintSidePieces(board, colors, 0); // Печать чёрных фигур

    for (int y1 = 1; y1 <= 8; y1++)          // Цикл по строкам (атакующая фигура)
    {
        for (int x1 = 1; x1 <= 8; x1++)      // Цикл по столбцам (атакующая фигура)
        {
            char piece1 = board[y1][x1];       // Символ атакующей фигуры
            if (piece1 == ' ' || !isupper(piece1)) continue; // Пропуск пустых клеток и некорректных фигур

            for (int y2 = 1; y2 <= 8; y2++)      // Цикл по строкам (атакуемая фигура)
            {
                for (int x2 = 1; x2 <= 8; x2++)  // Цикл по столбцам (атакуемая фигура)
                {
                    if (x1 == x2 && y1 == y2) continue; // Пропуск, если это та же клетка
                    char piece2 = board[y2][x2];   // Символ атакуемой фигуры
                    if (piece2 == ' ' || !isupper(piece2)) continue; // Пропуск пустых клеток и некорректных фигур

                    if (DoesPieceAttack(board, colors, x1, y1, x2, y2))  // Проверка возможности атаки
                    {
                        const char* side1 = colors[y1][x1] == 1 ? "White" : "Black"; // Сторона атакующей фигуры
                        const char* side2 = colors[y2][x2] == 1 ? "White" : "Black"; // Сторона атакуемой фигуры
                        printf("  %s (%s) at (%d,%d) attacks %s (%s) at (%d,%d)\n",
                            GetPieceName(piece1), side1, x1, 9 - y1,
                            GetPieceName(piece2), side2, x2, 9 - y2); // Вывод информации об атаке
                    }
                }
            }
        }
    }
}