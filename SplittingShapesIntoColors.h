#ifndef SPLITTINGSHAPESINTOCOLORS_H
#define SPLITTINGSHAPESINTOCOLORS_H

#include <stdbool.h>

// ��������� ������� ��� ������ � ������� �����
void InitializeColors(int colors[][10]); // ������������� ������
int AssignColorsToPieces(char board[][10], int colors[][10]); // ���������� ������ �������
bool CanAttack(int colors[][10], int x1, int y1, int x2, int y2); // �������� ����������� �����

#endif