/* FIXME : introduce elegant ways to reuse */
#include "swap.c"

void bubble_sort(List **head)
{
    if (head == NULL || (*head == NULL))
        return;

    int num_list = 0;
    int i = 0;
  
    List **pre_sub_head = head;
    List *sub_head;

    sub_head = *head;

    for (; sub_head ;sub_head = sub_head->next) {
        num_list = num_list + 1;	        
    }

    for (i=num_list-1; i > 0; i--) {
        sub_head = *head;
        pre_sub_head = head;
        for (int j= 0; j < i; j++) {
            if (sub_head->value < sub_head->next->value) {
                sub_head = swap(sub_head,sub_head,sub_head->next);
                *pre_sub_head = sub_head;
            }

            pre_sub_head = &((*pre_sub_head)->next);
            sub_head = sub_head->next;
        }
    }

    return;
}
