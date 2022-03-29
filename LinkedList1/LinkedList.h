/* Joshua Stefan Pang
 * 3/26/2022
 * LinkedList is a singly linkedlist that only keeps track of the head node.
 * Each individual node only keeps track of the next node. This linkedlist is
 * not thread safe. Care should be used to never 
 */

#ifndef _LINKEDLIST_H_INCLUDE_
#define _LINKEDLIST_H_INCLUDE_

#define LL_TYPE void*

#include "LinkedList.h"

typedef LinkedList;


/* NewLinkedList
 * CONSTRUCTOR
 * Simply returns an empty, fresh new linked list.
 * Returns: LinkedList just malloced.
 */
LinkedList* NewLinkedList(const LL_TYPE value);

/* ArrToLinkedList
 * CONSTRUCTOR
 * Parses the array and creates a new linkedlist from the pointers in the
 * array. This will crash if an array of 0 length is given; however,
 * this should never be the case because an array of length 0 should never
 * be made because of unobserved behaviors.
 * Takes:
 *   list[]: used to fill the new linkedlist
 * Returns: LinkedList just malloced with appropriate nodes and pointers.
 */
LinkedList* ArrToLinkedList(const LL_TYPE list[]);

/* FreeLinkedList
 * DECONSTRUCTOR
 * Frees all the relevant information for the linkedlist node and sets the
 * pointer to this node to NULL.
 * consistenct of the list when called.
 * Takes:
 *   LL: Pointer to a pointer of LinkedList to be removed. Makes it NULL
 *       after completion. 
 * Returns:
 *   The node after this one.
 * Precondition: LL is not NULL and *LL is not NULL
 */
LL_TYPE FreeLinkedList(const LinkedList** LL);

/* FreeAllLinkedList
 * DECONSTRUCTOR
 * Frees all the relevant information for the linkedlist and all associated
 * nodes.
 * Takes:
 *   LL: Pointer to a pointer of LinkedList to be removed. Makes it NULL
 *       after completion. 
 * Precondition: LL is not NULL and *LL is not NULL
 */
void FreeAllLinkedList(const LinkedList** LL);

/* AppendLinkedList
 * MANIPULATOR
 * Travels all the way down the linkedlist and adds a node to the end.
 * Takes:
 *   LL: LinkedList pointer to begin the "journey" to the tail of the list.
 *   value: Thing to insert into the new node.
 * Precondition: LL is not NULL
 * Returns: The freshly created node.
 */
LinkedList* AppendLinkedList(const LinkedList* LL, const LL_TYPE value);

/* InsertAfterLinkedList
 * MANIPULATOR
 * Just adds something after the current LL node.
 * Takes:
 *   LL: LinkedList pointer to begin the "journey" to the tail of the list.
 *   value: Thing to insert into the new node.
 * Precondition: LL is not NULL
 * Returns: The freshly created node.
 */
LinkedList* InsertAfterLinkedList(LinkedList* LL, const LL_TYPE value);


/* DeleteAfterLinkedList
 * MANIPULATOR
 * Deletes the node directly after this one and returns the value it held.
 * Takes:
 *   LL: Node right before node to be deleted.
 * Precondition: LL is not NULL
 * Returns: The deleted node's value.
 */
LL_TYPE DeleteAfterLinkedList(LinkedList* LL);

/* ReplaceLinkedList
 * MANIPULATOR
 * Keeps this node intact, but modify the pointer for the value it held.
 * Takes:
 *   LL: Node right before node to be deleted.
 * Precondition: LL is not NULL
 * Returns: The replaced value.
 */
LL_TYPE ReplaceLinkedList(LinkedList* LL, const LL_TYPE value);

/* FindNthLinkedList
 * ACCESSOR
 * Follows the list n times in an attempt to get the item at that location.
 * If it enocounters the end of the list, it returns NULL.
 * Takes:
 *   LL: node to to begin the "journey" to n items away.
 * Precondition: LL is not NULL
 * Returns: Node n items away, NULL if it is unable to jump n spaces.
 */
LinkedList* FindNthLinkedList(const LinkedList* LL, const int n);

/* LengthLinkedList
 * ACCESSOR
 * Follows Just length, jumps over the list n times until it reaches the end
 * and adds 1 each time.
 * Takes:
 *   LL: = Node where length begins calculation.
 * Returns: Number of nodes (length).
 */
int LengthLinkedList(const LinkedList* LL);

/* GetLinkedList
 * ACCESSOR
 * Simply get what this node points to. This could probably be turned into a
 * macro using defines as well...
 * Takes:
 *   LL: Some node, could be any node really.
 * Precondition: LL is not NULL
 * Returns: Whatever item this node is holding.
 */
LL_TYPE GetLinkedList(const LinkedList* LL);

#endif