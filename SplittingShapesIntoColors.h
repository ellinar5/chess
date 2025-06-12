#ifndef SPLITTINGSHAPESINTOCOLORS_H
#define SPLITTINGSHAPESINTOCOLORS_H

#include <stdbool.h>

// Прототипы функций для работы с цветами фигур
void InitializeColors(int colors[][10]); // Инициализация цветов
int AssignColorsToPieces(char board[][10], int colors[][10]); // Назначение цветов фигурам
bool CanAttack(int colors[][10], int x1, int y1, int x2, int y2); // Проверка возможности атаки

#endif