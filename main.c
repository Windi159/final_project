#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <io.h>

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

void crete_txt(char *file_name, int *length)
{
    if(*length <= 4)
    {
        *(file_name + 1 + *length) = '.';
        *(file_name + 2 + *length) = 't';
        *(file_name + 3 + *length) = 'x';
        *(file_name + 4 + *length) = 't';

        *length += 4;
    }

    else
    {
        if(*(file_name - 3 + *length) != '.' && *(file_name - 2 + *length) != 't' && *(file_name - 1 + *length) != 'x' && *(file_name + *length) != 't')
        {
            if(*length > 77)
                realloc(file_name, -(*length - 81) + 81);

            *(file_name + *length - 3) = '.';
            *(file_name + *length - 2) = 't';
            *(file_name + *length - 1) = 'x';
            *(file_name + *length) = 't';

            *length += -(*length - 80) + 80;
        }
    }
}

void save_file(struct canvas *save_setting, char *named_file, int size)
{
    FILE* user_text_file;
    char input[1420] = {};
    char name[size];

    for(int i = 0; i <= size; i++)
        name[i] = *(named_file + i);

    user_text_file = fopen(named_file, "w");

    for(int col = 0; col < 20; col++)
        for(int low = 0; low <= 70; low++)
            input[(71 * col) + low] = save_setting -> array[col][low];

    input[1419] = '\0';

    fputs(input, user_text_file);
    fclose(user_text_file);
}

void naming_file(struct canvas *file_setting)
{
    char *user_named_file;
    char override;
    int len = 0;

    user_named_file = calloc(81 ,  sizeof(char));

    printf("파일 이름을 정해주세요. 이름의 최대 길이는 80입니다.\n");
    scanf( "%s", user_named_file);

    while(user_named_file[len] != '\0')
        len++;

    char file_name = crete_txt(user_named_file, &len);

    if(_access(user_named_file, 0) != 0)
        save_file(file_setting, user_named_file, len);

    else
    {
        while(true)
        {
            printf("동일한 파일명이 존재합니다. 덮어 쓰시겠습니까?(y, n)\n");
            scanf(" %c", &override);

            if(override == 'y' || override == 'Y')
            {
                save_file(file_setting, user_named_file, len);
                break;
            }

            else if(override == 'n' || override == 'N')
            {
                printf("다른 이름을 입력해주세요.\n");
                naming_file(file_setting);
                break;
            }

            else
                continue;
        }
    }

}

void initialize(struct canvas *array)
{
    for(int col = 0; col <= 19; col++)
    {
        for(int low = 0; low <= 69; low++)
        {
            array -> array[col][low] = EMPTY;
        }

        array -> array[col][70] = '\n';
    }
}

void load_file()
{
    FILE* loading_file;
    char
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
                naming_file(&setting);
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
