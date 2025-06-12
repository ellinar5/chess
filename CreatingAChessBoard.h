#ifndef CREATINGACHESSBOARD_H_INCLUDED
#define CREATINGACHESSBOARD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Прототипы функций для работы с шахматной доской
void fillempty(char board[][10]); // Инициализация пустой доски
void DrawingBoard(char board[][10]); // Отрисовка доски
void LoadingShapes(char board[][10], const char* filename); // Загрузка фигур из файла

#endif
