#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

void showTable();
void test();
int getDigit(); //��ȡ����
void clr();
Status ifInit(int destroyStatus);   //�Ƿ��ʼ��
Status print(TElemType e);   //�������

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
    printf("        ѡ��1������ն�����T\n");
    printf("        ѡ��2���ݻٶ�����T\n");
    printf("        ѡ��3�����������T\n");
    printf("        ѡ��4���������������T\n");
    printf("        ѡ��5���������������T\n");
    printf("        ѡ��6���������������T\n");
    printf("        ѡ��7���������������T\n");
    printf("        ѡ��8���Թ������ǰ׺���ʽ��������ֵ\n");
    printf("        ѡ��0�˳�\n");
    printf("        #�Ŵ���պ���\n");
    printf("***************************\n");
}

void test()
{
    BiTree *t = (BiTree*)malloc(sizeof(BiTree));
    char definition[100];

    int num =1,status = 1;                                       //ѡ���ܡ��ݻٱ�
    while(num)
    {
        showTable();
        if(!status)
        {
            printf("ǰ�����  ��");
            PreOrderTraverse(*t,print);
            printf("\n");
            printf("�����������");
            InOrderTraverse(*t,print);
            printf("\n");
            printf("�������  ��");
            PostOrderTraverse(*t,print);
            printf("\n");
            printf("��α���  ��");
            LevelOrderTraverse(*t,print);
            printf("\n***************************\n");
        }
        num =getDigit();
        switch(num)
        {
            case 1:
            {
                if(status)
                {
                    if(InitBiTree(t))
                    {
                        printf("��ʼ���ɹ�\n");
                        status = 0;
                    }
                    else{printf("��ʼ��ʧ��\n");}
                }
                break;
            }
            case 2:
                if(ifInit(status))
                {
                    if((DestroyBiTree(t)))
                    {
                        printf("�ݻٳɹ�\n");
                        status = 1;
                    }
                    else{printf("�ݻ�ʧ��\n");}
                }
                break;
            case 3:
                if(ifInit(status))
                {
                    gets(definition);
                    if((CreateBiTree(t,definition)))
                    {
                        printf("�����ɹ�\n");
                    }
                    else{printf("�����ɹ�\n");}
                }
                break;
            case 4:
                if(ifInit(status))
                {
                    PreOrderTraverse(*t,print);
                }
                break;
            case 5:
                if(ifInit(status))
                {
                    InOrderTraverse(*t,print);
                }
                break;
            case 6:
                if(ifInit(status))
                {
                    PostOrderTraverse(*t,print);
                }
                break;
            case 7:
                if(ifInit(status))
                {
                    LevelOrderTraverse(*t,print);
                }
                break;
            case 8:
                if(ifInit(status))
                {
                    int val =  Value(*t);
                    printf("����ǣ�%d\n",val);
                }
                break;
        }
        clr();

    }
}


int getDigit()
{
    char num[20];
    gets(num);
    return atoi(num);   //�쳣����0
}


void clr()
{
    printf("���س�����:");
    getchar();
    system("CLS");
}

Status ifInit(int destroyStatus)
{
    if(destroyStatus){
        printf("        δ��ʼ��\n");
        return ERROR;
    }
    return SUCCESS;
}

Status print(TElemType e)
{
    printf("%c ",e);
    return SUCCESS;
}

