#define ABC(ARG0, ARG1) int ARG0##ARG1
#define ABC0(ARG0, ARG1) ABC(ARG0, ARG1)

ABC0(test, _filed(void))
{
    return 0;
}

int main(void)
{
    test_filed();
    return 0;
}
