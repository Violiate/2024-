#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct LinkList
{
    int number;
    struct LinkList* next;
}link;

int main()
{
    struct LinkList* head, * temp, * before, * now, * record, * RecordNext, * RecordBefore, * first;
    int times, i, j, shift_times, real_times, tempdata, flag2 = 0,judge_times;
    scanf("%d %d", &times, &shift_times);

    head = (struct LinkList*)malloc(sizeof(struct LinkList));
    before = head;
    judge_times = shift_times;
    while (shift_times > times)
    {
        shift_times = shift_times - times;
        flag2++;
    }


    
        real_times = times - shift_times;
    for (i = 0; i < times; i++)
    {
        now = (struct LinkList*)malloc(sizeof(struct LinkList));
        before->next = now;
        scanf("%d", &now->number);
        now->next = head->next;
        before = now;


    }
    first = head->next;
    now = first;
    if (times % 2 == 0 && judge_times % times != 0&& judge_times - times == 2)  //判断是否4 6，6 8，8 10特殊情况
    {
        for (i = 0; i < times/2; i++)       //从第一个元素跑，次数减半
        {

            for (j = 0; j < real_times; j++)
            {
                RecordBefore = now;
                now = now->next;


                if (j == real_times- 1)
                {
                    tempdata = now->number; now->number = first->number; first->number = tempdata;
                }


            }


        }  //此时奇数次项都交换到对应的位置了
        first = head->next->next;
        now = first;
        for (i = 0; i < times / 2; i++)  //从第二个元素跑，次数也是对半的
        {

            for (j = 0; j < real_times; j++)
            {
                RecordBefore = now;
                now = now->next;


                if (j == real_times  - 1)
                {
                    tempdata = now->number; now->number = first->number; first->number = tempdata;
                }


            }


        }

    }//偶数次项也换完了
    else
    {
        for (i = 0; i < times - 1; i++)
        {

            for (j = 0; j < real_times; j++)
            {
                RecordBefore = now;
                now = now->next;


                if (j == real_times - 1)
                {
                    tempdata = now->number; now->number = first->number; first->number = tempdata;
                }


            }


        }

    }
    
    now = head->next;
    for (i = 0; i < times; i++)
    {

        printf("%d", now->number);
        if (i + 1 != times)
        {
            printf(" ");
        }
        now = now->next;
    }
}