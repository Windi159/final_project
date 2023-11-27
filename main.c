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

    //반복문 필요
    print_guide();

    printf("\n사용할 기능을 선택해주세요.\n");
    printf("1.그리기 2.지우기 3.저장하기 4.불러오기 5.새 화면 6.종료\n");
    scanf("%d", &mode);

    if(mode == 1)
    {
        system("cls");
        printf("어느 위치에 점을 찍을까요?(입력 방식: 가로 세로 문자)\n");
        scanf("%d %d %s", &user.low, &user.col, &user.word);

        canvas[user.low][user.col] = user.word;
    }
}
