#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 20
#define WIDTH 70

struct user_input
{
    int low;
    int col;
    char word;
};

void print_guide()
{
    for(int h = 0; h <= HEIGHT + 1; h++)
    {
        if(h <= 1)
            printf("**");

        else
        {
            if(h <= 10)
                printf("0");

            printf("%d", h - 1);

        }

        for(int w = 0; w < WIDTH; w++)
        {
            if(h == 0)
                printf("%d", w % 10);

            else if(h == 1)
                printf("*");

            else
                printf("%c", canvas[h - 2][w]);
        }

        printf("\n");
    }
}

int main()
{
    char canvas[20][71];

    for(int low = 0; low < HEIGHT; low++)
        for(int col = 0; col < WIDTH; col++)
            canvas[low][col] = ' ';

    int mode;

    struct user_input user = {0, 0, ' '};

    //�ݺ��� �ʿ�
    print_guide();

    printf("\n����� ����� �������ּ���.\n");
    printf("1.�׸��� 2.����� 3.�����ϱ� 4.�ҷ����� 5.�� ȭ�� 6.����\n");
    scanf("%d", &mode);

    if(mode == 1)
    {
        system("cls");
        printf("��� ��ġ�� ���� �������?(�Է� ���: ���� ���� ����)\n");
        scanf("%d %d %s", &user.low, &user.col, &user.word);

        canvas[user.low][user.col] = user.word;
    }
}
