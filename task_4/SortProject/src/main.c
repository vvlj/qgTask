#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../inc/qgsort.h"

void showTable();
void test();
int getDigit(); //��ȡ����
void print(int *arr,int length);    //����
void clr();
int initArr(int *arr,int length);

int main()
{
    test();
    return 0;
}


void showTable()
{
    printf("                          \n");
    printf("                          \n");
    printf("ѡ����Թ���\n");
    printf("        ѡ��1����������\n");
    printf("        ѡ��2���鲢����\n");
    printf("        ѡ��3���鲢����\n");
    printf("        ѡ��4���������򣨵ݹ�棩\n");
    printf("        ѡ��5���������򣨷ǵݹ�棩\n");
    printf("        ѡ��6���������������ţ�\n");
    printf("        ѡ��7����������\n");
    printf("        ѡ��8��������������\n");
    printf("        ѡ��9����ɫ����\n");
    printf("        ѡ��0:��ʼ��\n");
    printf("        ѡ��11�˳�\n");
    printf("***************************\n");
}

void test()
{
    int num =1;                                       //ѡ���ܡ��ݻٱ�
    int length;
    printf("����������ĳ��ȣ�\n");
    length =getDigit();
    int *arr =(int*)malloc(sizeof(int)*length);
    initArr(arr,length);
    while(num != 11 )
    {
        clr();
        showTable();
        print(arr,length);
        printf("\n***************************\n");
        num =getDigit();
        switch(num)
        {
            case 12:
            {
                free(arr);
                printf("����������ĳ��ȣ�\n");
                length =getDigit();
                int *arr =(int*)malloc(sizeof(int)*length);
                initArr(arr,length);
                break;
            }
            case 1:
                insertSort(arr,length);
                break;
            case 2:
            {
                int temp[length];
                MergeSort(arr,0,length-1,temp);
                break;
            }
            case 4:
                QuickSort_Recursion(arr,0,length-1);
                break;
            case 5:
                QuickSort(arr,length);
                break;
            case 6:
                Partition(arr,0,length-1);
                break;
            case 7:
                CountSort(arr,length,100);
                break;
            case 8:
                RadixCountSort(arr,length);
                break;
            case 9:
                ColorSort(arr,length);
                break;
            case 3:
                {
                    printf("������k��ֵ��\n");
                    int num =getDigit();
                    findKth(arr,0,length-1,num);
                }
        }

    }
}


int getDigit()
{
    char num[20];
    gets(num);
    return atoi(num);   //�쳣����0

}

void print(int *arr,int length)
{
    for(int i = 0;i < length;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void clr()
{
    printf("���س�����:");
    getchar();
    system("CLS");
}

int initArr(int *arr,int length)
{
    printf("��ʼ�����飺\n");
    for(int i = 0;i<length;i++)
    {
        arr[i] = getDigit();
    }
}
