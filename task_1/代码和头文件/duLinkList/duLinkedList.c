#include "../head/duLinkedList.h"
#include <stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    DuLinkedList head = (DuLinkedList)malloc(sizeof(DuLNode));
    if(head != NULL){
        *L = head;
        head->prior =NULL;
        head ->next =NULL;
        return SUCCESS;
    }
    return ERROR;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    if(*L==NULL)return;
    DuLNode *curPrioNode =(*L)->prior,*nextNode;        //当前节点和临时节点
    DuLNode *curNextNode = (*L)->next;
	int num =1;
	while(curNextNode!=NULL){
        nextNode =curNextNode->next;
        free(curNextNode);
        curNextNode=nextNode;
        printf("        摧毁第后%d个节点成功\n",num++);
	}
	num =1;
    while(curPrioNode !=NULL){
        nextNode =curPrioNode->prior;
        free(curPrioNode);
        curPrioNode=nextNode;
        printf("        摧毁第前%d个节点成功\n",num++);
	}
	free(*L);
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if(p==NULL||q==NULL)return ERROR;
	DuLNode *tmpNode =p->prior;
	p->prior =q;
	q->prior =tmpNode;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if(p==NULL||q==NULL)return ERROR;
	DuLNode *tmpNode =p->next;
	p->next =q;
	q->next =tmpNode;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if(p ==NULL||p->next ==NULL)return ERROR;
    DuLNode *delNode =p->next;                  //要删除的指针
	*e =delNode->data;
	p->next =delNode->next;
	return  SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLNode *curNode;
    if(L!=NULL)curNode = L->next;
    printf("        头节点后：\n");
    while(curNode !=NULL){
        visit(curNode->data);
        curNode=curNode->next;
    }
    printf("\n");
    curNode =L->prior;
    printf("        头节点前：\n");
    while(curNode !=NULL){
        visit(curNode->data);
        curNode=curNode->prior;
    }
    printf("\n");
}

