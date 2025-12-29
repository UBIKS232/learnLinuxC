#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 5
#define MAX_COL 5

typedef struct pos
{
    int row;
    int col;
} pos4maze_t;

void print_maze(void);
int visit_maze(int row, int col);

#define WAY '0'
#define NOWAY '#'

char maze[MAX_ROW][MAX_COL] = {
    {WAY, NOWAY, WAY, NOWAY, WAY},
    {WAY, WAY, WAY, NOWAY, WAY},
    {WAY, NOWAY, NOWAY, NOWAY, WAY},
    {WAY, NOWAY, WAY, WAY, WAY},
    {WAY, WAY, WAY, NOWAY, WAY}};

int main(void)
{
    visit_maze(0, 0);

    return 0;
}

int visit_maze(int row, int col)
{
    if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
    {
        printf("(%d, %d): edge\n", row, col);
        return 0; // 边界
    }
    if (maze[row][col] != WAY)
    {
        printf("(%d, %d): wall\n", row, col);
        return 0; // 撞墙
    }

    printf("(%d, %d): new visit\n", row, col);
    maze[row][col] = '*';
    print_maze();

    if (row == MAX_ROW - 1 && col == MAX_COL - 1)
    {
        printf("(%d, %d): goal\n", row, col);
        return 1;
    }

    // 产生四个分支
    if (visit_maze(row, col + 1) ||
        visit_maze(row + 1, col) ||
        visit_maze(row, col - 1) ||
        visit_maze(row - 1, col))
    {
        printf("(%d, %d): on the way\n", row, col);
        return 1;
    }

    // maze[row][col] = 0;

    printf("(%d, %d): backwards\n", row, col);
    return 0;
}

void print_maze(void)
{
    printf("*********\n");
    int i, j;
    for (i = 0; i < MAX_ROW; i++)
    {
        for (j = 0; j < MAX_COL; j++)
            printf("%c ", maze[i][j]);
        putchar('\n');
    }
}