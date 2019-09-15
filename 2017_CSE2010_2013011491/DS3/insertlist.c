void insert_node(ListNode**phead,ListNode*p,ListNode*new_node){
if(*phead==NULL){
*phead=new_node;
new_node->link=NULL;

}
else if(p==NULL){
new_node->link=*phead;
*phead=new_node;
}
else{
new_node->link=p->link;
p->link=new_node;
}
