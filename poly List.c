/**********************
    리스트를 이용한 다항식 게산
    작성자; 선나운
    작성일: 12월 4일
*/
#include <stdio.h>
#include <stdlib.h>
#include "poly list_data.h"
#include "poly list_oper.h"
#include "poly list_oper_ex.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
    listType *L1, *L2, *rstL1, *rstL2;

    L1 = create();
    L2 = create();

    rstL1 = create();
    rstL2 = create();

    //다항식 1 생성
    insertLast(L1, 3, 12);
    insertLast(L1, 2, 8);
    insertLast(L1, 1, 10);
    prtPoly(L1);

    //다항식 2 생성
    insertLast(L2, 8, 12);
    insertLast(L2, -3, 10);
    insertLast(L2, 10, 6);
    prtPoly(L2);

    //rstL1 = L1+L2
    puts("L1 + L2 : ");
    polyAdd(L1, L2, rstL1);
    prtPoly(rstL1);

    /*//rstL2 = L1-L2
    puts("L1 - L2 : ");
    polySub(L1, L2, rstL2);
    prtPoly(rstL2);
    */

    delete (rstL1, 0);
    prtPoly(rstL1);
    delete (rstL1, 0);
    prtPoly(rstL1);
    delete (rstL1, 0);
    prtPoly(rstL1);
    delete (rstL1, 0);
    prtPoly(rstL1);
    delete (rstL1, 0);
    prtPoly(rstL1);

    delete (L1, 0);
    prtPoly(L1);
    delete (L1, 0);
    prtPoly(L1);
    delete (L1, 0);
    prtPoly(L1);

    delete (L2, 0);
    prtPoly(L2);
    delete (L2, 0);
    prtPoly(L2);
    delete (L2, 0);
    prtPoly(L2);

    free(L1);
    free(L2);
    free(rstL1);
    free(rstL2);

    return 0;
}