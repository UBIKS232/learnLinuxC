int main(void)
{
	char *p = "abcd";

	*p = 'A';
    // segmentation fault
    // p指向.rodata段，不允许改写，但编译器不会报错，在运行时会出现段错误

    return 0;
}