#include "lists.h"
/**
* pop_listint - deletes the head node of a linked list
* @head: points  the first element in the linked list
* Return: deleted data inside elements and
* 0 when empty
*/
int pop_listint(listint_t **head)
{
listint_t *temp;
int num;
if (!head || !*head)
return (0);
num = (*head)->n;
temp = (*head)->next;
free(*head);
*head = temp;
return (num);
}
