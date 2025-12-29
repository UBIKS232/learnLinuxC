#include <stdio.h>

char source[] =
    "This Content hoho       is ok \
    ok? \
\
    \
        file system \
    uttered words ok ok \
? end.";

char *shrink_space(char *dest, const char *src, size_t n);

int main()
{
    char buffer[500] = {0};

    printf("%s\n", source);
    printf("%s\n", shrink_space(buffer, source, sizeof(source)));

    return 0;
}

char *shrink_space(char *dest, const char *src, size_t n)
{
    char *tmp = dest;
    int space_flag = 0;

    // if(n > sizeof(*dest)) return NULL; // FATAL
    while (*src != '\0')
    {
        while ((*src == '\n') || (*src == '\t') || (*src == ' ') || (*src == '\r'))
        {
            src++;
            if ((*src != '\n') && (*src != '\t') &&
                (*src != ' ') && (*src != '\r'))
            {
                space_flag = 1;
                break;
            }
        }
        if (space_flag == 1)
        {
            *(dest++) = ' ';
        }
        *(dest++) = *(src++);
        space_flag = 0;
    }

    return tmp;
}

/*
SHRINK_SPACE(3)            C Library Functions           SHRINK_SPACE(3)

NAME
       shrink_space - 压缩字符串中的空白字符（空格、制表符、换行符、回车符），
                      将连续的空白字符替换为单个空格

SYNOPSIS
       #include <stddef.h>

       char *shrink_space(char *dest, const char *src, size_t n);

DESCRIPTION
       shrink_space() 函数用于处理源字符串 src，将其中所有连续出现的空白
       字符（包括 ' '、'\t'、'\n'、'\r'）压缩为一个空格，并将处理结果写入
       目标缓冲区 dest。

       参数说明：
         • dest：指向目标缓冲区的指针，用于存储处理后的字符串。
         • src：指向源字符串的指针，函数将从此读取原始数据。
         • n：保留参数（当前实现未使用），未来可用于指定 dest 缓冲区大小以
           防止溢出。

       函数逻辑如下：
         - 遍历 src 中的每个字符；
         - 当遇到空白字符序列时，跳过全部连续空白，仅在后续非空白字符前
           插入一个空格；
         - 非空白字符直接复制到 dest；
         - 最终在 dest 末尾不自动添加 '\0'（调用者需自行确保字符串以空字符
           结尾，若需要）。

       注意：当前实现未对 dest 缓冲区长度做边界检查，调用者必须确保 dest
       足够大以容纳处理后的字符串（最坏情况长度不超过 strlen(src) + 1）。

RETURN VALUE
       成功时返回 dest 的初始地址（即传入的 dest 指针）。

EXAMPLE
       #include <stdio.h>
       #include <string.h>

       int main(void)
       {
           const char *input = "Hello\t\t\n\r  World!  \n";
           char output[100];

           shrink_space(output, input, sizeof(output));
           // 注意：应根据实际输出长度设置终止符
           // 此处仅为示意，正确做法是记录写入位置并加 '\0'
           output[ actual length ] = '\0';

           printf("Result: \"%s\"\n", output);
           // 可能输出: "Hello World! "
           return 0;
       }

CAVEATS
         • 该函数不会在输出字符串末尾自动添加 '\0'，调用者需自行处理。
         • 参数 n 在当前版本中未被使用，但保留以支持未来安全扩展。
         • 若 src 以空白字符结尾，输出字符串末尾会保留一个额外空格。

BUGS
         • 未处理 dest 缓冲区溢出风险。
         • 对于全空白输入（如 "   \t\n"），可能产生一个孤立空格而无后续内容。

SEE ALSO
       isspace(3), strcpy(3), memmove(3)

AUTHOR
       本函数由用户自定义实现，非标准 C 库函数。
*/