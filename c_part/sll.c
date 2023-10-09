#include <stdlib.h>
#include <stdio.h>

struct Node{
    int val;
    struct Node *next;
};

typedef struct Node *node;

node createNode(int value){
    node temp;
    temp = (node)malloc(sizeof(struct Node));
    temp->val = value;
    temp->next = NULL;

    return temp;
}

node add_start(node list, int value){
    node temp;
    temp = createNode(value);
    temp->next = list;
    return temp;
}

node add_end(node list, int value){
    node temp, p;
    temp = createNode(value);
    p = list;
    while(p->next != NULL){
        p = p->next;
    }

    p->next = temp;

    return list;
}

node delete_at(node list, int index){
    if(index == 0){
        list = list->next;
        return list;
    }
    node temp;
    temp = list;
    int i=0;
    while(i<index-1){
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
    return list;
}

node insert_at(node list, int index, int value){
    node temp = createNode(value);
    if(index == 0){
        temp->next = list;
        return temp;
    }

    node itr = list;
    int i = 0;
    while(i<index-1){
        itr = itr->next;
        i++;
    }
    temp->next = itr->next;
    itr->next = temp;
    return list;
}

void show(node list){
    node p;
    p = list;
    while(p != NULL){
        printf("%d->", p->val);
        p = p->next;
    }
    printf("\n");
}


int main(){
    node lst;
    lst = createNode(1);
    lst = add_start(lst, 2);
    lst = add_start(lst, 3);
    lst = add_end(lst, 4);
    lst = add_end(lst, 5);
    show(lst);
    lst = delete_at(lst, 2);
    show(lst);
    lst = insert_at(lst, 0, 11);
    show(lst);
    lst = insert_at(lst, 2, 12);
}