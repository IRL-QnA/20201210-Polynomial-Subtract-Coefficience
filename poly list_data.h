typedef int element;

typedef struct listNode
{
  element coef;
  int expon;
  struct listNode *link;
} listNode;

typedef struct
{
  listNode *head;
  int size; //노드 갯수
} listType;