#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "SplittingShapesIntoColors.h"

// ������������� ������� ������ (��� ������ -1)
void InitializeColors(int colors[][10]) 
{
    for (int y = 0; y < 10; y++) 
    {
        for (int x = 0; x < 10; x++) 
        {
            colors[y][x] = -1; // -1 �������� ���������� ������
        }
    }
}

// ���������� ������ ������� (����� ��� ������)
int AssignColorsToPieces(char board[][10], int colors[][10]) 
{
    int count = 0; // ������� �����
    int coords[64][2]; // ������ ��������� �����

    // ���� ��������� ���� ����� �� �����
    for (int y = 1; y <= 8; y++)
    {
        for (int x = 1; x <= 8; x++) 
        {
            if (isupper(board[y][x]))  // ���� ������ �������� ������
            {
                coords[count][0] = x; // ���������� ���������� X
                coords[count][1] = y; // ���������� ���������� Y
                count++; // ���������� ��������
            }
        }
    }

    if (count < 2)  // �������� �� ����������� ���������� �����
    {
        printf("Error: Not enough pieces (min 2 required).\n");
        return 0;
    }

    int white = 1, black = 0; // ����� � ������

    // ���������� ������ �������
    for (int i = 0; i < count; i++) 
    {
        int x = coords[i][0];
        int y = coords[i][1];

        if (count % 2 == 0)  // ׸���� ���������� �����
        {
            colors[y][x] = (i < count / 2) ? white : black; // ������ �������� - �����, ������ - ������
        }
        else  // �������� ���������� �����
        {
            if (i == 0) colors[y][x] = white; // ������ ������ - �����
            else if (i == count - 1) colors[y][x] = black; // ��������� ������ - ������
            else colors[y][x] = (i % 2 == 0) ? white : black; // ����������� ������
        }
    }

    return 1; // �������� ����������
}

// ��������, ����� �� ������ ��������� ���� ����� (������ �����)
bool CanAttack(int colors[][10], int x1, int y1, int x2, int y2)
{
    return colors[y1][x1] != colors[y2][x2]; // ����� ��������, ���� ����� ������
}

