#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    //0과 1을 true와 false로 표현하기 위해 선언
#include <io.h>

#define EMPTY ' '

struct canvas
{
    char user_input;
    char array[20][71];
};

void printing(struct canvas *show_setting) //화면에 array를 출력하는 부분
{
    for(int row = 0; row <= 21; row++)  //array는 19가 최대 값이지만, 1234564890 와 ****를 표현하기 위해 21
    {
        if(row <= 1)    //2번째줄까지 **가 공통적으로 들어가므로 1보다 작을때 **출력하도록 설정
            printf("**");

        else
        {
            if(row <= 10)    //10이 넘어가지 않는다면 숫자 앞에 0을 출력
                printf("0");

            printf("%d", row - 1);    //숫자 출력
        }


        for(int col = 0; col < 70; col++)
        {
            if(row == 0)
                printf("%d", (col + 1) % 10);    //1234567890를 표현하기위해 

            else if(row == 1)
                printf("*");    //1번째 줄에 *******.. 를 출력하기

            else
                printf("%c", show_setting -> array[row - 2][col]);    //array값 출력
        }
        printf("\n");
    }
}

void save_file(struct canvas *save_setting, char *named_file, int size)
{
    FILE* user_text_file;
    char name[size];

    for(int i = 0; i <= size; i++)
        name[i] = *(named_file + i);    //named_file이 주솟값 이므로 name에 named_file의 값 저장

    user_text_file = fopen(named_file, "w");    //파일을 쓰기 모드로 열기

    save_setting -> array[19][70] = '\0';    //마지막(20번째줄 71번 칸?)는 null문자 삽입 
    fprintf(user_text_file, save_setting -> array);    //파일에 array의 값을 저장

    fclose(user_text_file);    //파일 닫기
}

void naming_file(struct canvas *file_setting)
{
    char user_named_file[80] = {};
    char override;
    int len = 0;

    printf("파일 이름을 정해주세요. 이름의 최대 길이는 80입니다.\n");
    scanf( " %s", user_named_file);

    while(user_named_file[len] != '\0')
        len++;

    if(_access(user_named_file, 0) != 0)    // 프로젝트 파일 안에 user_named_file이라는 파일이 없다면
        save_file(file_setting, user_named_file, len);

    else    // 프로젝트 파일 안에 user_named_file이라는 파일이 있다면
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
    for(int row = 0; row <= 19; row++)
    {
        for(int col = 0; col <= 69; col++)
            array -> array[row][col] = EMPTY;    //0~69(총 70)을 빈칸으로 채움

        array -> array[row][70] = '\n';    //71번 칸을 \n으로 저장
    }
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
            printf("1.그리기 2.지우기 3.저장하기 4.새 화면 5.종료\n");

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
                initialize(&setting);
                break;
            }

            else if (mode_select == '5')
                exit(2);

            else
            {
                printf("잘못된 입력입니다. 다시 입력해주세요.\n");
                break;
            }
        }

        system("cls");
    }
}
