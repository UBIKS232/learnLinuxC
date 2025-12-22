#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point
{
    int row, col;
} stack[512];
int top = 0;

void push(struct point p)
{
    stack[top++] = p;
}

struct point pop(void)
{
    return stack[--top];
}

int is_empty(void)
{
    return top == 0;
}

int maze[MAX_ROW][MAX_COL] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}};

void print_maze(void)
{
    int i, j;
    for (i = 0; i < MAX_ROW; i++)
    {
        for (j = 0; j < MAX_COL; j++)
            printf("%d ", maze[i][j]);
        putchar('\n');
    }
    printf("*********\n");
}

enum direction
{
    start,
    right, // right
    down,  // down
    left,  // left
    up     // up
};

// start right down left up
enum direction predecessor[MAX_ROW][MAX_COL] = {start};

/**
 * 将maze对应点记作已访问(2)
 * 在predecessor对应点写回退(backwards)的方向
 * 将当前点(通过"上下左右"更新过的点)压栈
 */
void visit(int row, int col, enum direction backwards)
{
    struct point visit_point = {row, col};
    maze[row][col] = 2;
    predecessor[row][col] = backwards;
    push(visit_point);
}

// print predecessor
void print_predecessor(int row, int col)
{
    // if(predecessor[p.row][p.col] == start){
    //     return;
    // }
    // p = predecessor[p.row][p.col]; // 将p记为上一个点
    switch (predecessor[row][col])
    {
    case start:
        return;
    case right:
        col++;
        print_predecessor(row, col);
        break;
    case down:
        row++;
        print_predecessor(row, col);
        break;
    case left:
        col--;
        print_predecessor(row, col);
        break;
    case up:
        row--;
        print_predecessor(row, col);
        break;
    default:
        break;
    }
    // print_predecessor(p);
    switch (predecessor[row][col])
    {
    case start:
        printf("[%d,%d]: start\n", row, col);
        return;
    case right:
        printf("[%d,%d]: left\n", row, col);
        break;
    case down:
        printf("[%d,%d]: up\n", row, col);
        break;
    case left:
        printf("[%d,%d]: right\n", row, col);
        break;
    case up:
        printf("[%d,%d]: down\n", row, col);
        break;
    default:
        break;
    }
}

int main(void)
{
    struct point p = {0, 0};

    maze[p.row][p.col] = 2;
    push(p);

    while (!is_empty())
    {
        p = pop();               // 从栈中取出一个点
        if (p.row == MAX_ROW - 1 /* goal */
            && p.col == MAX_COL - 1)
            break;
        if (p.col + 1 < MAX_COL /* right */
            && maze[p.row][p.col + 1] == 0)
            visit(p.row, p.col + 1, left);
        if (p.row + 1 < MAX_ROW /* down */
            && maze[p.row + 1][p.col] == 0)
            visit(p.row + 1, p.col, up);
        if (p.col - 1 >= 0 /* left */
            && maze[p.row][p.col - 1] == 0)
            visit(p.row, p.col - 1, right);
        if (p.row - 1 >= 0 /* up */
            && maze[p.row - 1][p.col] == 0)
            visit(p.row - 1, p.col, down);
        print_maze();
    }
    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
    {
        for (int i = 0; i < MAX_ROW; i++)
        {
            // printf("{");
            for (int j = 0; j < MAX_COL; j++)
            {
                int direc = predecessor[i][j];
                printf("%d\t", direc);
            }
            // printf("}\n");
            printf("\n");
        }
        printf("*********\n");

        print_predecessor(p.row, p.col);
        printf("*********\n");

        // printf("[%d, %d]\n", p.row, p.col);
        // while (predecessor[p.row][p.col].row != -1)
        // {
        //     p = predecessor[p.row][p.col]; // 将p记为上一个点
        //     printf("[%d, %d]\n", p.row, p.col);
        // }
    }
    else
        printf("No path!\n");

    return 0;
}