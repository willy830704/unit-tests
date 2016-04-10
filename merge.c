#include "swap.c"

void merge_sort(List** head){

    if( head==NULL || (*head)==NULL || ((*head)->next) == NULL){
	return;
    }

    List *left = *head;
    List *right = (*head)->next;
    List *nextnode = NULL;
    List *lastnode = NULL;


    while(right){
	right = right->next;
	if(right){
	    left=left->next;
	    right=right->next;
	}
    }
    
    right = left->next;
    left->next = NULL;
    left = *head;	

    merge_sort(&left);
    merge_sort(&right);   

    *head = NULL;
    while(left && right){
	if(left->value < right->value){
	    nextnode = left;
	    left = left->next;	    
	}else{
	    nextnode = right;
	    right = right->next;
	}

	if(*head){
	    lastnode->next = nextnode;	    
	}else{
	    *head = nextnode;
	    
	}
	lastnode = nextnode;
    }
    
    lastnode->next = (left) ? left : right;
}
