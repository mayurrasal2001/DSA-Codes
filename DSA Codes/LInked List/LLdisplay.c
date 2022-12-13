
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;   //*next pointer of type struct node called as the SELF REFRENTIAL POINTER
}*first=NULL;
                                                                //Pointers---> *first , *t , *last, *next
//1.LL Creation                                                              
void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
 
    for(i=1;i<n;i++)
    {
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;    //last nodes address of the first node will pointing to the newly created nodesss(many nodes)
    last=t;          //last become move to next node therefore the t will be the newnode
    }
}

//2.Display LL using Iterative and Recursive way
void Display(struct Node *p)
{
     while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void RDisplay(struct Node *p)
{
  if(p!=NULL)
 {
    RDisplay(p->next);
    printf("%d ",p->data);
 } 
}

//3.Count the number of elements using Iterative and recursive way

int count(struct Node *p)
{
    int n=0;
    while(p!=NULL)
    {
        n++;
        p=p->next;
    }
    return n;
}

//Recurssive Way

int Rcount(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return count(p->next)+1;
}


//4.Sum of the Linked List elements

int sum( struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum=sum+ p->data;
        p=p->next;
    }
    return sum;
}

int Rsum(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return sum(p->next)+p->data;
}


//5.Searching in the Linked List

//Iterative Way

struct Node * search(struct Node *p, int key)
{
    while(p!=NULL)   //when the condition is true then only it enters into the while loop
    {
        if(key==p->data)
            return p;          //returning the node
        else
            p=p->next;
    }
    return NULL;
}


//more impressive code for the liearsearch

struct Node * Lsearch (struct Node *p ,int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;   
    }
    return NULL;
}

//Recursive way

struct Node * RLsearch(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    else
        if(key==p->data)
            return p;
        else
            return RLsearch(p->next, key);
}

void insert(struct Node *p, int index, int x )
{
    struct Node *t;      //temporary pointer for creating the new node 
    int i;

    if(index < 0 || index > count(p))    /*checking the condition where if index is less than the 0 then condition will false
                                         OR condition is index is greater than the count means the if we insert element at the after position 4 ie.last element of the array and we give input as insert after the 10th position that means the count is more */
        return ;
    else
        t=(struct Node *) malloc(sizeof(struct Node));  //create the temporary node and link
        t->data=x;                                      //initialise some data

        if(index==0)                                     //means insert before the first
        {
            t->next=first;
            first=t; 
        }
        else                                                //means insert after the given position
            {
                for(i=0; i< index-1; i++)                   //traversing the linked list upto the index after which we want to insert the element 
                {
                    p=p->next;                          //upto reach the given index
                }   
                t->next=p->next;
                p->next=t;
            }          
}


//insert at the sorted list

void Insertsort(struct Node *p, int x)
{
    struct Node *t, *q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=t;

    else
    {

    
        while(p!=NULL && p->data < x)
        {
            q=p;
            p=p->next;
        }

        if(p==first)
        {
            t->next=first;
            first=t;
        }
            
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }        
}

int Delete(struct Node*p, int index)
{
    struct Node *q=NULL;
    int x=-1,i;
    if(index < 1 || index > count(p))
        return -1;

    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }

    else
        for(i=0; i<index-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;                 //before deleting the node we assigned value ti the x for returning to the function
        free(p);
        return x;
}

int isSorted(struct Node *p)
{   
    int x=-65536;
    while(p!=NULL)
    {
        if(p->data < x)             //means link is not sorted
            return 0;               
        else
            x=p->data;              //means store the p->data in the x and p will move to the next node
            p=p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{   
    p=first;
    struct Node *q=p->next;

    while(q!=NULL)
    {
        if(p->data != q->data)           //p->data not equal to q->data QR equal to
        {
            p=q;
            q=q->next;
        }
        else   
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void Reverse1(struct Node *p)
{
    int *A, i=0;
    struct Node *q=p;             //means the q will pointing on the first node
    A=(int *)malloc(sizeof(int)*count(p));

    while(q!=NULL)          //this loop copying all of elements of the linked list in the array
    {
        A[i]=q->data;       
        q=q->next;
        i++;
    }
    q=p;                  //when the q=Null then again q will pointing to the first node for the again copy elements in th LL
    i--;                   //this will help us to copying elements in the reverse order

    while(q!=NULL)         //this loop copying all of the elemnts of the array in Linked list
    {
        q->data=A[i];   
        q=q->next;
        i--;
    }
}

void Reverse2(struct Node *p)         //this function can work using the sliding pointers p,q,r
{
    struct Node *q=NULL, *r=NULL;

    while(p!=NULL)
    {
        r=q;                        //r move on the q 
        q=p;                        //q move to p
        p=p->next;                  //p move to next node
        q->next=r;                  //this step can used for the linking between the q and r and also used for the Reversing the links
    }
    first=q;                        //after p goes out of loop means p becomes NULL then first will pointing to the q 
}

void Reverse3(struct Node *q, struct Node *p)
{
    if(p!=NULL)
    {
        Reverse3(p, p->next);           //Reverse(q is move to the p ,, and p is move to the next node)
        p->next=q;                      //this step is for the returing the values and linking between them
    }
    else
        first=q;                        //when p becomes Null then for reversing the links 
}








int main()
{
// struct Node *temp;      //because Linear search function return a node

 int A[]={10,20,30,40,50};
 create(A,5);  
Reverse2(NULL,first);                     //(Reverse1), (Reverse3) these are 2 functions
Display(first);


// int A[]={10,10,12,14,11,22,22,22,23,24,25,56};
// create(A,12); 
// RemoveDuplicate(first);
// Display(first);

//  if(isSorted(first))
//     printf("Linklist is in the sorted order");
// else
//     printf("Linklist is not sorted\n");


// printf("Deleted Elements are %d \n", Delete(first,5));
// Display(first);

//  insert(first,6,20);
//  Display(first);

// Insertsort(first,4);  //this function is also run when the Linked list is also empty means no any elements in the array
// Display(first);
// printf("\n \n");

//Lsearch
// temp=Lsearch(first, 10);   //for searching the data
// temp=Lsearch(first, 332);  //here we first found the 10 then 10 will at first position the 332 will found and now it will at the first position
//  if(temp!=NULL)
//     printf("\nKey is found %d \n", temp->data);
//  else
//     printf("Key is not found");

//Display
//Display(first);                                                      //Recursive function
//RDisplay(first);                                                  //Recurrsive 

//count
//printf("\n Lenth of the Linked List is %d ",count(first));       //count function
//printf("Lenth of the Linked List is %d \n ",Rcount(first));    //Recursive

//sum
//printf("\n Sum of the linked list is %d ", sum(first));         //Sum Function
//printf("Sum of the linked list is %d ", Rsum(first));         //Recursive

 return 0;

}






