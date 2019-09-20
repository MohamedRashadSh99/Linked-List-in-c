#include <stdio.h>
#include <stdlib.h>


//////////////////////////////structure of Linked List//////////////////////


typedef struct Node
{
    int data;
    struct Node*next;
    struct Node*prev;
}Node;


typedef struct
{
    Node*head;
    Node*tail;
}DoublyLinkedList;

DoublyLinkedList EmptyList = {NULL,NULL};

Node*newNode(int val)
{
    Node*n=malloc (sizeof(Node));
    n->data=val;
    n->next=NULL;
    n->prev=NULL;
    return n;
}
void initializer_list(DoublyLinkedList *list)
{
    list->head=NULL;
    list->tail=NULL;

}
void addHead(DoublyLinkedList *list,int value)
{
    Node*n=newNode(value);
    if(list->tail==NULL)
        {list->head=list->tail=n;}
    else
    {n->next=list->head;
    list->head->prev=n;
    list->head=n;
    }
}
void addtail(DoublyLinkedList *list,int value)
{
    Node*n=newNode(value);
    if(list->head==NULL)
        {list->head=list->tail=n;}
    else
    {n->prev=list->tail;
    list->tail->next=n;
    list->tail=n;
    }
}
int isempty(DoublyLinkedList *list)
{
    if(list->head==NULL)
       return 1;
    return 0;
}


//////////////////////Converting////////////////////////
DoublyLinkedList convertArrayToDoublyLinkedList(int array[],int size)
{

int i;

DoublyLinkedList My_list;
initializer_list(&My_list);
for(i=0;i<size;i++)
{
addtail(&My_list,array[i]);
}
printf("you convert successfully.\n");
printf("\n");
printf("If you want to see your linked list :\n");

printlnListForward(My_list);
printlnListBackward(My_list);

return My_list;
}
///////////////////////////////destroy///////////////
void destroy(DoublyLinkedList*list)
{
    while(list->head!=NULL)
    {
        list->head=list->head->next;
    }
    printf("you destroyed this list successfully\n");

}


////////////////////////////////dublicated////////////
DoublyLinkedList dup(DoublyLinkedList list)
{
DoublyLinkedList listdouble1,listdouble2,listdouble3;
initializer_list(&listdouble1);
initializer_list(&listdouble2);
initializer_list(&listdouble3);

listdouble1=list;
listdouble2=list;

while(listdouble1.head!=NULL)
{
    addtail(&listdouble3,listdouble1.head->data);
    listdouble1.head=listdouble1.head->next;
}
printf("NOW You dup lists successfully\n");
printlnListForward(listdouble3);
printf("\n");



return listdouble3;
}

/////////////////////////////////concatinating/////////
DoublyLinkedList concatenate(DoublyLinkedList list1,DoublyLinkedList list2)
{
DoublyLinkedList listdouble1,listdouble2,listdouble3;
initializer_list(&listdouble1);

initializer_list(&listdouble3);
int c;
listdouble1=list1;
listdouble2=list2;

while(listdouble1.head!=NULL)
{
    addtail(&listdouble3,listdouble1.head->data);
    listdouble1.head=listdouble1.head->next;
}
while(listdouble2.head!=NULL)
{
    addtail(&listdouble3,listdouble2.head->data);
    listdouble2.head=listdouble2.head->next;
}

printf("NOW You cocatinate 2 lists successfully\n");
printf("\n");

return listdouble3;
}
/////////////////////////////////countelements////////
int length(DoublyLinkedList list )
{
    int count;
    count=0;
    DoublyLinkedList List_test;
    List_test=list;
    while(List_test.head!=NULL)
        {count++;
        List_test.head=List_test.head->next;
        }
   return count;
}

/////////////////////////////////IsPAlindrom//////////
int isPalindrome(DoublyLinkedList list)
{
    DoublyLinkedList list_test;
    list_test=list;
    while(list_test.head!=NULL)
    {
        if(list_test.head->data!=list_test.tail->data)
           {return 0;}
               list_test.head=list_test.head->next;
        list_test.tail=list_test.tail->prev;
    }
    return 1;

}



////////////////////ARE EQUAL///////////////////////


int areEqual(DoublyLinkedList list1,DoublyLinkedList list2)
{
    DoublyLinkedList list_test1,list_test2;
    list_test1=list1;   list_test2=list2;
    while(list_test1.head!=NULL&&list_test2.head!=NULL)
    {
        if(list_test1.head->data!=list_test2.head->data)

            {return 0;}

        list_test1.head=list_test1.head->next;
        list_test2.head=list_test2.head->next;
    }
    if(list_test1.head==NULL&&list_test2.head==NULL)
    {return 1;}
    else
    {
     return 0;}
}





///////////////////////printing///////////////////////
void printlnListBackward(DoublyLinkedList list)
{
    DoublyLinkedList LPrint;
    LPrint=list;
    printf("your linked list in backward print is[");
    while(LPrint.head!=NULL){
        printf("%d",LPrint.tail->data);
          LPrint.tail=LPrint.tail->prev;
        LPrint.head=LPrint.head->next;
        if(LPrint.head!=NULL)
            printf("<->");
}
printf("]");
printf("\n");
}

void printlnListForward(DoublyLinkedList list)
{
    DoublyLinkedList LPrint;
    LPrint=list;
    printf("your linked list in forward print is[");
    while(LPrint.head!=NULL){
        printf("%d",LPrint.head->data);
        LPrint.head=LPrint.head->next;
        if(LPrint.head!=NULL)
            printf("<->");
}
printf("]");
printf("\n");
}
/*
*
*/
void Investigate(char* title, DoublyLinkedList list)
{
    printf("%s\n", title);
    printf("List = ");
    printlnListForward(list);
    printf("Reverse List = ");
    printlnListBackward(list);
    printf("List Length = %u\n", length(list));
    printf("List isPalindrome = %d\n", isPalindrome(list));
    printf("...................................................\n");
}
/*
*
*/
void testConcatenate1(DoublyLinkedList list1, DoublyLinkedList list2)
{
    DoublyLinkedList list3, list4, emptyList1;

    list3 = dup(list1);
    Investigate("List3 = dup(List1)\n==================", list3);
    emptyList1 = dup(EmptyList);
    Investigate("EmptyList1 = dup(EmptyList)\n===========================", emptyList1);
    DoublyLinkedList list5 = concatenate(list3, emptyList1);
    Investigate("List5 = List3<->EmptyList1\n==========================",list5);
    destroy(&list5);
    Investigate("List5 (after destroy)\n=====================", list5);
//destroy(&list3); //already destroyed when list5 got destroyed
//destroy(&emptyList1); //already destroyed when list5 got destroyed
}
/*
*
*/
void testConcatenate2(DoublyLinkedList list1, DoublyLinkedList list2)
{
    DoublyLinkedList list3, list4, emptyList1;
    list3 = dup(list1);
    emptyList1 = dup(EmptyList);
    DoublyLinkedList list6 = concatenate(emptyList1, list3);
    Investigate("List6 = EmptyList1<->List3\n==========================",list6);
    destroy(&list6);
    Investigate("List6 (after destroy)\n=====================", list6);
//destroy(&list3); //already destroyed when list6 got destroyed
//destroy(&emptyList1); //already destroyed when list6 got destroyed
}
/*
*
*/
void testConcatenate3(DoublyLinkedList list1, DoublyLinkedList list2)
{
    DoublyLinkedList list3, list4, emptyList1;
    list3 = dup(list1);
    list4 = dup(list2);
    DoublyLinkedList list7 = concatenate(list3, list4);
    Investigate("List7 = List3<->List4\n=====================", list7);
    destroy(&list7);
    Investigate("List7 (after destroy)\n=====================", list7);
//destroy(&list3); //already destroyed when list7 got destroyed
//destroy(&list4); //already destroyed when list7 got destroyed
}
/*
*
*/
void testConcatenate()
{
    int array1[] = {0, 1, 2, 3, 4, 5, 6};
    int array2[] = {7, 8, 9};




    DoublyLinkedList list1 = convertArrayToDoublyLinkedList(array1,sizeof(array1)/sizeof(*array1));
    Investigate("List1\n=====", list1);
    DoublyLinkedList list2 = convertArrayToDoublyLinkedList(array2,sizeof(array2)/sizeof(*array2));
    Investigate("List2\n=====", list2);
    testConcatenate1(list1, list2);
    testConcatenate2(list1, list2);
    testConcatenate3(list1, list2);
    destroy(&list1);
    destroy(&list2);
}
/*
*
*/
void testPalindrome()
{
    int array3[] = {0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0};
    int array4[] = {7, 8, 9, 9, 8, 7};
    DoublyLinkedList list8 = convertArrayToDoublyLinkedList(array3,sizeof(array3)/sizeof(*array3));
    Investigate("List8\n=====", list8);
    DoublyLinkedList list9 = convertArrayToDoublyLinkedList(array4,sizeof(array4)/sizeof(*array4));
    Investigate("List9\n=====", list9);
    destroy(&list8);
    destroy(&list9);
}
/*
*
*/
void testAreEqual()
{
    int array5[] = {0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0};
    int array6[] = {7, 8, 9, 9, 8, 7};
    int array7[] = {0, 1, 2, 3, 4, 5};
    DoublyLinkedList list10 = convertArrayToDoublyLinkedList(array5,sizeof(array5)/sizeof(*array5));
    Investigate("List10\n=====", list10);
    DoublyLinkedList list11 = convertArrayToDoublyLinkedList(array6,sizeof(array6)/sizeof(*array6));
    Investigate("List11\n=====", list11);
    DoublyLinkedList list12 = convertArrayToDoublyLinkedList(array7,sizeof(array7)/sizeof(*array7));
    Investigate("List12\n=====", list12);
    DoublyLinkedList emptyList1 = dup(EmptyList);
    Investigate("EmptyList1 = dup(EmptyList)\n===========================", emptyList1);
    DoublyLinkedList emptyList2 = dup(EmptyList);
    Investigate("EmptyList2 = dup(EmptyList)\n===========================", emptyList2);
    printf("areEqual(List10, List10) = %d\n", areEqual(list10, list10));
    printf("areEqual(List10, List11) = %d\n", areEqual(list10, list11));

    printf("areEqual(List10, List12) = %d\n", areEqual(list10, list12));
    printf("areEqual(List11, List10) = %d\n", areEqual(list11, list10));
    printf("areEqual(List10, EmptyList1) = %d\n", areEqual(list10,emptyList1));
    printf("areEqual(EmptyList1, List10) = %d\n", areEqual(emptyList1,list10));
    printf("areEqual(EmptyList1, EmptyList2) = %d\n", areEqual(emptyList1,emptyList2));
    destroy(&list10);
    destroy(&list11);
    destroy(&list12);
}
/*
*
*/
main()
{
    int c1,c2,data,i,j;
    DoublyLinkedList l1,l2;
    initializer_list(&l1);
    initializer_list(&l2);
    printf("enter size1: ");
    scanf("%d",&c1);
    int ar1[c1];

    for(i=0;i<c1;i++)
    {
        printf("enter element at index %d: ",i);
        scanf("%d",&ar1[i]);
        //addtail(&list1,data);
    }

    printf("enter size2: ");
    scanf("%d",&c2);
    int ar2[c2];
    for(i=0;i<c2;i++)
    {
        printf("enter element at index %d: ",i);
        scanf("%d",&ar2[i]);
       // addtail(&list2,data);
    }
    l1=convertArrayToDoublyLinkedList(ar1,c1);
     l2=convertArrayToDoublyLinkedList(ar2,c2);
    dup(l1);
    dup(l2);
    concatenate(l1,l2);
   printf("empty1=%d\n",isempty(&l1)) ;
   printf("empty2=%d\n",isempty(&l2)) ;


    printlnListForward(l1);
    printlnListBackward(l1);
     printlnListForward(l2);
    printlnListBackward(l2);

 printf("areEqual=%d,palind1=%d,palind2=%d\n",areEqual(l1,l2),isPalindrome(l1), isPalindrome(l2));
 printf("size1=%d,size2=%d",length(l1),length(l2));
 destroy(&l1);destroy(&l2);
     printlnListForward(l1);
         printlnListForward(l2);
 printf("size1=%d,size2=%d\n",length(l1),length(l2));
  printf("isempty for list1:%d\n",isempty(&l1)) ;
   printf("isempty for list2:%d\n",isempty(&l2)) ;
  //  testConcatenate();
  //  testPalindrome();
   // testAreEqual();
    return 0;
}
