void error(char *msg){
    printf("%s\n", msg);
    exit(1);
}

listType *create(){
    listType *L = (listType*)malloc(sizeof(listType));
    if(L == NULL)
         error("memory allocation error");
    L->head = NULL;
    L->size = 0;
    return L;
}

int inEmpty(listType *L){
    //return L->head == NULL;
    return L->size == 0;
}


int getSize(listType *L){
    return L->size;
}

/*리스트 안에서 pos위치의 노드 주소를 리턴
  pos 범위:0~size-1 
 */
listNode *getNodeAt(listType *L, int pos){
    listNode *node = L->head;
    if(pos<0 || pos>L->size)
        return NULL;
    for(int i=0; i<pos; i++)
        node = node->link;
    return node;
}

//phead: 리스트의 헤드포인처의 포인터
//prev: 선행노드
//newNode: 삽입될 노드
void insertNode(listNode **phead, listNode *prev, listNode *newNode){
    //공백 리스트 일때 
    if(*phead == NULL){
        newNode->link = NULL;
        *phead = newNode;
    }
    //선행노드가 없으면 첫 번째 노드 삽입 
    else if(prev == NULL){
        newNode->link = *phead;
        *phead = newNode;
    }
    //선행노드 뒤에 삽입(일반적인 경우) 
    else{
        newNode->link = prev->link;
        prev->link = newNode; 
    }
} 
//list의 원하는 pos에 item 삽입
//pos range:0~size-1
void insert(listType *L, int pos, element coef, int expon){
    listNode *prev; //선행노드 저장
    if(pos>=0 && pos<=L->size){
        listNode *newNode = (listNode*)malloc(sizeof(listNode));
        if(newNode == NULL)
           error("memory allocation error");
        newNode->coef = coef;
        newNode->expon = expon;
        prev = getNodeAt(L, pos-1);
        insertNode(&(L->head), prev, newNode);
        L->size++;
        
    } 
} 

void prtPoly(listType *L){
    listNode *node = L->head;
    printf("polynomial = ");
    while(node != NULL){
        printf("%dX^%d + ", node->coef, node->expon);
        node = node->link;
    }
    printf("NULL\n");
}

/*void prtListRecur(listNode *head){
    listNode *node = head;
    if(node != NULL){
        printf("%d ->", node->data);
        prtListRecur(node->link);
    }
}
*/

void removeNode(listNode **phead, listNode *prev, listNode *removed){
    if(prev == NULL)//연결 노드 삭제
        *phead = (*phead)->link;
    else
        prev->link = removed->link;
    free(removed); 
}

/*void delete(listType *L, int pos){
    if (!isEmpty(L) && pos >= 0 && pos<L->size){
        listNode *prev = getNodeAt(L, pos-1);
        removeNode(&(L->head), prev, (prev!=NULL)?prev->link:L->head);
        L->size--;
    }
}
*/

/*element getEntry(listType *L, int pos){
    listNode *node;
    if(pos<0 || pos>=L->size)
        error("position error");
    node = getNodeAt(L, pos);
    return node->data;
}
*/

/*listNode *search(listType *L, element item){
    listNode *node;
    node = L->head;
    while(node != NULL){
        if(node->data == item)
            return node;
        node = node->link;
    }
    return node;
}
*/

void insertLast(listType *L, element coef, int expon){
    insert(L, getSize(L), coef, expon);
}