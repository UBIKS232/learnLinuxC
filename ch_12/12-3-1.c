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

struct point predecessor[MAX_ROW][MAX_COL] = {
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
};

/**
 * 将maze对应点记作已访问(2)
 * 在predecessor对应点写传入的点(pre), 记录上一个点, 表示来自上一个点
 * 将当前点(通过"上下左右"更新过的点)压栈
 */
void visit(int row, int col, struct point pre)
{
    struct point visit_point = {row, col};
    maze[row][col] = 2;
    predecessor[row][col] = pre;
    push(visit_point);
}

// print predecessor
void print_predecessor(struct point p)
{
    if(predecessor[p.row][p.col].row == -1){
        return;
    }
    p = predecessor[p.row][p.col]; // 将p记为上一个点
    print_predecessor(p);
    printf("[%d, %d]\n", p.row, p.col);
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
            visit(p.row, p.col + 1, p);
        if (p.row + 1 < MAX_ROW /* down */
            && maze[p.row + 1][p.col] == 0)
            visit(p.row + 1, p.col, p);
        if (p.col - 1 >= 0 /* left */
            && maze[p.row][p.col - 1] == 0)
            visit(p.row, p.col - 1, p);
        if (p.row - 1 >= 0 /* up */
            && maze[p.row - 1][p.col] == 0)
            visit(p.row - 1, p.col, p);
        print_maze();
    }
    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
    {
        for (int i = 0; i < MAX_ROW; i++)
        {
            // printf("{");
            for (int j = 0; j < MAX_COL; j++)
            {
                struct point tmp_point = predecessor[i][j];
                if (tmp_point.row < 0 && tmp_point.col > 0)
                {
                    printf("[%d, %d]\t", tmp_point.row, tmp_point.col);
                }
                else if (tmp_point.col < 0 && tmp_point.row > 0)
                {
                    printf("[ %d,%d]\t", tmp_point.row, tmp_point.col);
                }
                else if (tmp_point.col < 0 && tmp_point.row < 0)
                {
                    printf("[%d,%d]\t", tmp_point.row, tmp_point.col);
                }
                else
                {
                    printf("[ %d, %d]\t", tmp_point.row, tmp_point.col);
                }
            }
            // printf("}\n");
            printf("\n");
        }
        printf("*********\n");

        print_predecessor(p);
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