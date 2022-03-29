/* Joshua Stefan Pang
 * 3/26/2022
 * LinkedList is a singly linkedlist that only keeps track of the head node.
 * Each individual node only keeps track of the next node. For just documentation
 * of the library functions, look into LinkedLish.h
 */

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

typedef struct LinkedList
{
  LL_TYPE value;
  struct LinkedList* Next;
} LinkedList;

/* NewLinkedList
 * CONSTRUCTOR
 * Simply returns an empty, fresh new linked list.
 */
LinkedList* NewLinkedList(const LL_TYPE value)
{
  LinkedList* Node = malloc(sizeof(LinkedList));

  //Null check.
  if(Node == NULL)
  {
    exit(EXIT_FAILURE);
    fprintf(stderr, "LinkedList Error: NewLinkedList(const LinkedList* LL)"
    "called with LL as NULL\n");
  }

  //Put value in node, set next to NULL.
  Node->value = value;
  Node->Next = NULL;
}

/* ArrToLinkedList
 * CONSTRUCTOR
 * Parses the array and creates a new linkedlist from the pointers in the
 * array. This will crash if an array of 0 length is given; however,
 * this should never be the case because an array of length 0 should never
 * be made because of unobserved behaviors.
 */
LinkedList* ArrToLinkedList(const LL_TYPE list[])
{
  //Calculate length
  int length = sizeof(list)/sizeof(list[0]);

  //Put the items into the linked list.
  LinkedList* First_Node = malloc(sizeof(LinkedList));
  First_Node = NewLinkedList(list[0]);
  for(int i = 1; i < length; i++)
  {
    
  }
}

/* FreeLinkedList
 * DECONSTRUCTOR
 * Frees all the relevant information for the linkedlist node and sets the
 * pointer to this node to NULL.
 * consistenct of the list when called.
 */
LL_TYPE FreeLinkedList(const LinkedList** LL)
{
  if(LL == NULL)
  {
    fprintf(stderr, "LinkedList Error: FreeNextLinkedList(const LinkedList* LL)"
    "called with LL as NULL\n");
		return;
  }

  //Grab linkedlist value, to return it.
  LL_TYPE value = (*LL)->value;
  free(*LL);
  *LL = NULL;
  return value;
}

/* FreeAllLinkedList
 * DECONSTRUCTOR
 * Frees all the relevant information for the linkedlist and all associated
 * nodes.
 */
void FreeAllLinkedList(const LinkedList** LL)
{
  if(LL == NULL)
  {
    fprintf(stderr, "LinkedList Error: FreeAllLinkedList(const LinkedList* LL)"
    "called with LL as NULL\n");
		return;
  }

  //Start going down the list.
  LinkedList* Node = *LL;
  LinkedList* Next = Node->Next;
  while(Node != NULL)
  {
    free(Node);
    Node=Next;
    Next=Next->Next;
  }

  *LL = NULL;
}

/* AppendLinkedList
 * MANIPULATOR
 * Travels all the way down the linkedlist and adds a node to the end.
 */
LinkedList* AppendLinkedList(const LinkedList* LL, const LL_TYPE value)
{
  if(LL == NULL)
  {
    fprintf(stderr, "LinkedList Error: GetLinkedList(const LinkedList* LL)"
    "called with LL as NULL\n");
		return;
  }

  LinkedList* Last = LL;
  for(LinkedList* I = LL->Next; I != NULL; I=I->Next)
  {
    LinkedList* Last = I;
  }

  //Malloc new node and change Next values for the one at the end.
  LinkedList* Node = malloc(sizeof(LinkedList));
  Node->value = value;
  Node->Next = NULL;
  Last->Next = Node;

  return Node;
}

/* InsertAfterLinkedList
 * MANIPULATOR
 * Just adds something after the current LL node.
 */
LinkedList* InsertAfterLinkedList(LinkedList* LL, const LL_TYPE value)
{
  if(LL == NULL)
  {
    fprintf(stderr, "LinkedList Error: GetLinkedList(const LinkedList* LL)"
    "called with LL as NULL\n");
		return;
  }

  //Malloc new node and change Next values.
  LinkedList* Node = malloc(sizeof(LinkedList));
  Node->value = value;
  Node->Next = LL->Next;
  LL->Next = Node;

  return Node;
}


/* DeleteAfterLinkedList
 * MANIPULATOR
 * Deletes the node directly after this one and returns the value it held.
 */
LL_TYPE DeleteAfterLinkedList(LinkedList* LL)
{
  if(LL == NULL)
  {
    fprintf(stderr, "LinkedList Error: GetLinkedList(const LinkedList* LL)"
    "called with LL as NULL\n");
		return;
  }

  //Get next and value, change LL->Next, and free Next.
  LinkedList* Next = LL->Next;
  LL_TYPE old_value = Next->value;
  LL->Next = Next->Next;
  free(Next);

  return old_value;
}

/* ReplaceLinkedList
 * MANIPULATOR
 * Keeps this node intact, but modify the pointer for the value it held.
 */
LL_TYPE ReplaceLinkedList(LinkedList* LL, const LL_TYPE value)
{
  if(LL == NULL)
  {
    fprintf(stderr, "LinkedList Error: ReplaceLinkedList(const LinkedList* LL, "
    "const LL_TYPE value) called with LL as NULL\n");
		return;
  }

  //Just grab old value and replace it.
  LL_TYPE old_value = LL->value;
  LL->value = value;

  return old_value;
}

/* FindNthLinkedList
 * ACCESSOR
 * Follows the list n times in an attempt to get the item at that location.
 * If it enocounters the end of the list, it returns NULL.
 */
LinkedList* FindNthLinkedList(const LinkedList* LL, const int n)
{
  if(LL == NULL)
  {
    fprintf(stderr, "LinkedList Error: FindNthLinkedList(const LinkedList* LL)"
    "called with LL as NULL\n");
		return;
  }

  LinkedList* I = LL;
  for(int i = 0; i < n; i++)
  {
    if (I == NULL) return NULL;
    I=I->Next;
  }

  return I;
}

/* LengthLinkedList
 * ACCESSOR
 * Follows Just length, jumps over the list n times until it reaches the end
 * and adds 1 each time.
 */
int LengthLinkedList(const LinkedList* LL)
{
  int length = 0;
  for(LinkedList* I = LL; I != NULL; I=I->Next)
  {
    length++;
  }

  return length;
}

/* GetLinkedList
 * ACCESSOR
 * Simply get what this node points to. This could probably be turned into a
 * macro using defines as well...
 */
LL_TYPE GetLinkedList(const LinkedList* LL)
{
  if(LL == NULL)
  {
    fprintf(stderr, "LinkedList Error: GetLinkedList(const LinkedList* LL)"
    "called with LL as NULL\n");
		return;
  }

  return LL->value;
}