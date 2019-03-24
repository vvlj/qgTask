#include "../head/linkedList.h"
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    LinkedList head = (LinkedList)malloc(sizeof(LNode));
    if(head != NULL){
        *L = head;
        head ->next =NULL;
        return SUCCESS;
    }
    return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LNode *curNode =*L,*nextNode;    //当前节点和临时节点
	int num =0;
	while(curNode !=NULL){
        nextNode =curNode->next;
        free(curNode);
        curNode=nextNode;
        printf("        摧毁第%d个节点成功\n",num++);
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if(p==NULL||q==NULL)return ERROR;
	LNode *tmpNode =p->next;
	p->next =q;
	q->next =tmpNode;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if(p->next ==NULL)return ERROR;
    LNode *delNode =p->next;   //要删除的指针
	//*e =delNode->data;
	printf("值%d",delNode->data);
	p->next =delNode->next;
	return  SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    if(L!=NULL)L =L->next;
    while(L !=NULL){
        visit(L->data);
        L=L->next;
    }
    printf("\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    Status status =ERROR;
    while(L !=NULL){
        if(L->data==e){
            status =SUCCESS;
            break;
        }
        L =L->next;
    }
    return status;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    if(*L==NULL) return ERROR;
    LNode *tmpNode;
    LNode *newHead = (LinkedList)malloc(sizeof(LNode));
    newHead->next =NULL;
    LNode *curNode =*L;
    while(curNode !=NULL){
        tmpNode =curNode->next;
        curNode->next =newHead->next;
        newHead->next =curNode;
        curNode =tmpNode;
    }
    *L=newHead->next;                                       //不增加新的节点
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    if(L==NULL ||L->next==NULL) return ERROR;
    LNode *slowPointer =L->next;
    LNode *fastPointer =L->next->next;
    while(fastPointer !=NULL){
        if (slowPointer==fastPointer)
            return SUCCESS;
        if(fastPointer->next==NULL)
            break;
        fastPointer =fastPointer->next->next;
        slowPointer =slowPointer->next;
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    if(*L!=NULL&&(*L)->next!=NULL){
        LNode *leftNode=(*L),*rightNode;
        *L =leftNode ->next;                               //左指针变成头部
        while(leftNode->next!=NULL){
            rightNode =leftNode->next->next;               //右节点
            leftNode->next->next=leftNode;        //左节点next头节点
            leftNode->next=rightNode;          //头节点next右节点
            leftNode =rightNode;               //左节点
            if(rightNode==NULL)break;
        }
    }
    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    if(*L==NULL ||(*L)->next==NULL) return NULL;
    LNode *slowPointer =(*L)->next;
    LNode *fastPointer =(*L)->next->next;
    while(fastPointer !=NULL)
    {
        if(fastPointer->next==NULL)
            break;
        fastPointer =fastPointer->next->next;
        slowPointer =slowPointer->next;
    }
    return slowPointer;
}
