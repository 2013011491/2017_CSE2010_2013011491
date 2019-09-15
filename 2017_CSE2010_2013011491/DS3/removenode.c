void remove_node(ListNode**phead,ListNode*p,ListNode*removed){
if(p==NULL)
*phead=*phead->link;
else
p->link=removed->link;
free(removed);
}

