#ifndef CHECKATTACKS_H_INCLUDED
#define CHECKATTACKS_H_INCLUDED

#include <stdbool.h>

// ��������� ������� ��� �������� ����
bool DoesPieceAttack(char board[][10], int colors[][10], int x1, int y1, int x2, int y2); // �������� ����� ����� ������
void CheckAllAttacks(char board[][10], int colors[][10]); // �������� ���� ��������� ���� �� �����

#endif