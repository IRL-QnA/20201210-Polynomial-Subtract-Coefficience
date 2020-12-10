//polyAdd(): rstL = L1 + L2

void polyAdd(listType *L1, listType *L2, listType *rstL)
{
  listNode *nodeL1 = L1->head;
  listNode *nodeL2 = L2->head;

  element sum = 0;
  while (nodeL1 && nodeL2)
  { //모두 NULL이 아니면 참
    //L1 차수 == L2차수
    if (nodeL1->expon == nodeL2->expon)
    {
      sum = nodeL1->coef + nodeL2->coef;
      if (sum != 0)
        insertLast(rstL, sum, nodeL1->expon);
      nodeL1 = nodeL1->link;
      nodeL2 = nodeL2->link;
    }
    //L1 차수 < L2차수
    else if (nodeL1->expon < nodeL2->expon)
    {
      insertLast(rstL, nodeL2->coef, nodeL2->expon);
      nodeL2 = nodeL2->link;
    }
    //L1 차수 > L2차수
    else
    {
      insertLast(rstL, nodeL1->coef, nodeL1->expon);
      nodeL1 = nodeL1->link;
    }
  }
  //나머지 항들의 계수를 rstL로 복사
  for (; nodeL1; nodeL1 = nodeL1->link)
    insertLast(rstL, nodeL1->coef, nodeL1->expon);
  for (; nodeL2; nodeL2 = nodeL2->link)
    insertLast(rstL, nodeL2->coef, nodeL2->expon);
}

//polySub(): rstL = L1 - L2

void polySub(listType *L1, listType *L2, listType *rstL)
{
  listNode *nodeL1 = L1->head;
  listNode *nodeL2 = L2->head;

  element sub = 0;
  while (nodeL1 && nodeL2)
  { //모두 NULL이 아니면 참
    //L1 차수 == L2차수
    if (nodeL1->expon == nodeL2->expon)
    {
      sub = nodeL1->coef - nodeL2->coef;
      if (sub != 0)
        insertLast(rstL, sub, nodeL1->expon);
      nodeL1 = nodeL1->link;
      nodeL2 = nodeL2->link;
    }
    //L1 차수 < L2차수
    else if (nodeL1->expon < nodeL2->expon)
    {
      insertLast(rstL, nodeL2->coef, nodeL2->expon);
      nodeL2 = nodeL2->link;
    }
    //L1 차수 > L2차수
    else
    {
      insertLast(rstL, nodeL1->coef, nodeL1->expon);
      nodeL1 = nodeL1->link;
    }
  }
  //나머지 항들의 계수를 rstL로 복사
  for (; nodeL1; nodeL1 = nodeL1->link)
    insertLast(rstL, nodeL1->coef, nodeL1->expon);
  for (; nodeL2; nodeL2 = nodeL2->link)
    insertLast(rstL, nodeL2->coef, nodeL2->expon);
}