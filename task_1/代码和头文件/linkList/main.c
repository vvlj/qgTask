#include <stdio.h>
#include "../�����ͷ�ļ�/head/LinkedList.h"
void showLinkedListTable();
void LinkedListTest();
void printNodeValue(ElemType e);
Status ifInit(int destroyStatus);
int main()
{
    LinkedListTest();
    return 0;
}

void showLinkedListTable()
{
    printf("                          \n");
    printf("                          \n");
    printf("ѡ����Ե�������\n");
    printf("        ѡ��1����ʼ��\n");
    printf("        ѡ��2���ݻ�\n");
    printf("        ѡ��3������\n");
    printf("        ѡ��4��ɾ��\n");
    printf("        ѡ��5������\n");
    printf("        ѡ��6������\n");
    printf("        ѡ��7����ת\n");
    printf("        ѡ��8��ѭ���ж�\n");
    printf("        ѡ��9��ż����ת\n");
    printf("        ѡ��10:�м�ڵ�\n");
    printf("        ѡ��0:�˳�\n");
    printf("***************************\n");

}
void LinkedListTest()
{
    int num,destroyStatus =1;                                       //ѡ���ܡ��ݻٱ�־
    LinkedList *testList;
    testList = (LinkedList*)malloc(sizeof(LinkedList));            //��ָ��ṹ��ָ���ָ������ڴ�
    while(num)
    {
        showLinkedListTable();
        if(!destroyStatus){
            TraverseList(*testList,printNodeValue);
            printf("***************************\n");
        }
        scanf("%d",&num);
        switch(num){
            case 1:
                if(destroyStatus){
                    if(InitList(testList)){
                        printf("        ���������ʼ���ɹ�\n");
                        destroyStatus =0;
                    }
                    else{printf("        ���������ʼ��ʧ��\n");}
                }
                else{printf("        ���������ѳ�ʼ��\n");}
                break;
            case 2:
                if(ifInit(destroyStatus)){
                    DestroyList(testList);
                    destroyStatus=1;
                    printf("        ��������ݻٳɹ�\n");
                }
                break;
            case 3:
                if(ifInit(destroyStatus)){
                    printf("        ������һ��ֵ���뵽ͷ�ڵ��һ���ڵ�:\n");
                    LNode *q =(LinkedList)malloc(sizeof(LNode));
                    scanf("%d",&q->data);
                    if(InsertList(*testList,q))
                        printf("        ����%d�ɹ�\n",q->data);
                    else{printf("        ����%dʧ��\n",q->data);}
                }
                break;
            case 4:
                if(ifInit(destroyStatus)){
                    printf("        ɾ���ڵ��һ���ڵ�\n");
                    ElemType *e;
                    if(DeleteList(*testList,*e))
                        printf("        �ɹ�");
                    else{printf("        ʧ��");}
                    }
                break;
            case 5:
                if(ifInit(destroyStatus)){
                    printf("        �������ÿ���ڵ��ֵ\n");
                    TraverseList(*testList,printNodeValue);
                }
                break;
            case 6:
                if(ifInit(destroyStatus)){
                    printf("        ������һ��ֵ������\n");
                    ElemType e;
                    scanf("%d",&e);
                    if(SearchList(*testList,e)){
                        printf("%d����",e);
                    }
                    else{printf("%d������",e);}
                }
                break;
            case 7:
                if(ifInit(destroyStatus)){
                    if(ReverseList(testList))
                        printf("        ��ת��������ɹ�\n");
                    else{printf("        ��ת��������ʧ��\n");}
                }
                break;
            case 8:
                if(ifInit(destroyStatus)){
                    if(IsLoopList(*testList))
                        printf("        ��������ѭ��\n");
                    else{printf("        ��������ѭ��\n");}
                }
                break;
            case 9:
                if(ifInit(destroyStatus)){
                    LNode *reverseHead =ReverseEvenList(testList);
                    if(reverseHead !=NULL)
                        printf("        ż���ڵ㷴ת�ɹ�\n");
                    else{printf("        ż���ڵ㷴תʧ��\n");}
                }
                break;
            case 10:
                if(ifInit(destroyStatus)){
                    LNode *midNode =FindMidNode(testList);
                    if(midNode !=NULL)
                        printf("        �м�ڵ�ֵ��%d\n",midNode->data);
                    else{printf("        ���м�ڵ�\n");}
                }
                break;
        }
        printf("���س�����:");
        getchar();
        getchar();
        system("CLS");
}
}

void printNodeValue(ElemType e)
{
    printf("%d ->",e);
}

Status ifInit(int destroyStatus)
{
    if(destroyStatus){
        printf("        ��������δ��ʼ��\n");
        return ERROR;
    }
    return SUCCESS;
}
