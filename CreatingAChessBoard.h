#ifndef CREATINGACHESSBOARD_H_INCLUDED
#define CREATINGACHESSBOARD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ��������� ������� ��� ������ � ��������� ������
void fillempty(char board[][10]); // ������������� ������ �����
void DrawingBoard(char board[][10]); // ��������� �����
void LoadingShapes(char board[][10], const char* filename); // �������� ����� �� �����

#endif
