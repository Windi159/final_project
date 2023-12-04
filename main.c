#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY ' '

struct canvas
{
    char user_input;
    char array[20][71];
};

void printing(struct canvas *show_setting)
{
    for(int col = 0; col <= 21; col++)
    {
        if(col <= 1)
            printf("**");

        else
        {
            if(col <= 10)
                printf("0");

            printf("%d", col - 1);
        }


        for(int low = 0; low < 70; low++)
        {
            if(col == 0)
                printf("%d", (low + 1) % 10);

            else if(col == 1)
                printf("*");

            else
                printf("%c", show_setting -> array[col - 2][low]);
        }
        printf("\n");
    }
}

void save_file(struct canvas *save_setting)
{
    FILE* user_text_file;
    char user_named_file[] = {};

    printf("파일 이름을 정해주세요\n");
    scanf("%s", user_named_file);

    user_text_file = fopen(user_named_file, "w");
    for(int col = 0; col < 20; col++)
        fwrite(save_setting -> array[col], 1, sizeof(char), user_text_file);
}

void initialize(struct canvas *array)
{
    for(int col = 0; col <= 19; col++)
        for(int low = 0; low <= 70; low++)
            array -> array[col][low] = EMPTY;
}

int main() {
    struct canvas setting;

    char mode_select;
    int x, y;

    initialize(&setting);

    while (true) {
        printing(&setting);

        while(true)
        {
            printf("\n             사용할 기능을 선택해주세요.\n");
            printf("1.그리기 2.지우기 3.저장하기 4.불러오기 5.새 화면 6.종료\n");

            scanf(" %c", &mode_select);

            if (mode_select == '1')
            {
                printf("어떤 문자를 표시하시겠습니까?\n");
                scanf(" %c", &setting.user_input);

                printf("어디에 문자를 표시하시겠습니까?\n입력 예시 : 가로 세로\n");
                scanf(" %d %d", &x, &y);

                setting.array[y - 1][x - 1] = setting.user_input;

                break;
            }


            else if (mode_select == '2')
            {
                printf("어디에 문자를 지우시겠습니까?\n입력 예시 : 가로 세로\n");
                scanf(" %d %d", &x, &y);

                setting.array[y - 1][x - 1] = EMPTY;
                break;
            }


            else if (mode_select == '3')
            {
                save_file(&setting);
                break;
            }

            else if (mode_select == '4')
            {
                printf("불러오기 만들기");
            }

            else if (mode_select == '5')
            {
                initialize(&setting);
                break;
            }

            else if (mode_select == '6')
                break;

            else
                printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }

        if(mode_select == '6')
            break;

        system("cls");
    }
}
