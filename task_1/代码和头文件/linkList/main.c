#include <stdio.h>
#include "../代码和头文件/head/LinkedList.h"
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
    printf("选择测试单链表功能\n");
    printf("        选项1：初始化\n");
    printf("        选项2：摧毁\n");
    printf("        选项3：插入\n");
    printf("        选项4：删除\n");
    printf("        选项5：遍历\n");
    printf("        选项6：搜索\n");
    printf("        选项7：反转\n");
    printf("        选项8：循环判断\n");
    printf("        选项9：偶数反转\n");
    printf("        选项10:中间节点\n");
    printf("        选项0:退出\n");
    printf("***************************\n");

}
void LinkedListTest()
{
    int num,destroyStatus =1;                                       //选择功能、摧毁标志
    LinkedList *testList;
    testList = (LinkedList*)malloc(sizeof(LinkedList));            //给指向结构体指针的指针分配内存
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
                        printf("        测试链表初始化成功\n");
                        destroyStatus =0;
                    }
                    else{printf("        测试链表初始化失败\n");}
                }
                else{printf("        测试链表已初始化\n");}
                break;
            case 2:
                if(ifInit(destroyStatus)){
                    DestroyList(testList);
                    destroyStatus=1;
                    printf("        测试链表摧毁成功\n");
                }
                break;
            case 3:
                if(ifInit(destroyStatus)){
                    printf("        请输入一个值插入到头节点后一个节点:\n");
                    LNode *q =(LinkedList)malloc(sizeof(LNode));
                    scanf("%d",&q->data);
                    if(InsertList(*testList,q))
                        printf("        插入%d成功\n",q->data);
                    else{printf("        插入%d失败\n",q->data);}
                }
                break;
            case 4:
                if(ifInit(destroyStatus)){
                    printf("        删除节点后一个节点\n");
                    ElemType *e;
                    if(DeleteList(*testList,*e))
                        printf("        成功");
                    else{printf("        失败");}
                    }
                break;
            case 5:
                if(ifInit(destroyStatus)){
                    printf("        遍历输出每个节点的值\n");
                    TraverseList(*testList,printNodeValue);
                }
                break;
            case 6:
                if(ifInit(destroyStatus)){
                    printf("        请输入一个值来搜索\n");
                    ElemType e;
                    scanf("%d",&e);
                    if(SearchList(*testList,e)){
                        printf("%d存在",e);
                    }
                    else{printf("%d不存在",e);}
                }
                break;
            case 7:
                if(ifInit(destroyStatus)){
                    if(ReverseList(testList))
                        printf("        反转测试链表成功\n");
                    else{printf("        反转测试链表失败\n");}
                }
                break;
            case 8:
                if(ifInit(destroyStatus)){
                    if(IsLoopList(*testList))
                        printf("        测试链表循环\n");
                    else{printf("        测试链表不循环\n");}
                }
                break;
            case 9:
                if(ifInit(destroyStatus)){
                    LNode *reverseHead =ReverseEvenList(testList);
                    if(reverseHead !=NULL)
                        printf("        偶数节点反转成功\n");
                    else{printf("        偶数节点反转失败\n");}
                }
                break;
            case 10:
                if(ifInit(destroyStatus)){
                    LNode *midNode =FindMidNode(testList);
                    if(midNode !=NULL)
                        printf("        中间节点值是%d\n",midNode->data);
                    else{printf("        无中间节点\n");}
                }
                break;
        }
        printf("按回车返回:");
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
        printf("        测试链表未初始化\n");
        return ERROR;
    }
    return SUCCESS;
}
