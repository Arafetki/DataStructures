#include <iostream>
using namespace std;

typedef struct Node{
    int Data;
    struct Node* next,*prev;
}Node;

Node* Newnode(int data){
    Node* ptr=new Node;
    ptr->Data=data;
    ptr->prev=NULL;
    ptr->next=NULL;
    return ptr;
}


// inserts a new node on the front of the list.
void Push(Node** head,int data){
    Node* ptr=Newnode(data);
    ptr->next=(*head);
    (*head)->prev=ptr;
    (*head)=ptr;
}
// Inserts a new node at the end
void Append(Node** head,int data){
    Node* new_node=Newnode(data);
    Node* ptr=(*head);
    if ((*head)==NULL){
        *head=new_node;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        new_node->prev=ptr;
        ptr->next=new_node;

    }

}
//inserts a new node after a given node.
void InsertAfter(Node* prev,int data){
    if (prev==NULL){
        cout<<"Prev node cannot be null";
    }
    else{
        Node* new_node=Newnode(data);
        new_node->prev=prev;
        new_node->next=prev->next;
        prev->next->prev=new_node;
        prev->next=new_node;
    }

}

//inserts a new node before a given node.

void InsertBefore(Node *next,int data){
    if (next!=NULL && next->prev!=NULL){
        Node* new_node=Newnode(data);
        new_node->next=next;
        new_node->prev=next->prev;
        next->prev->next=new_node;
        next->prev=new_node;

    }


}

// Delete The first node of the list.
void Pop(Node** head){
    Node* ptr=(*head);
    if (ptr!=NULL){
            if (ptr->next==NULL){
                (*head)=NULL;
            }
            else {
                ptr->next->prev=NULL;
                (*head)=ptr->next;

            }


    }


}

// Delete The Last node of the list.

void DeleteLast(Node** head){
    if ((*head)!=NULL){
        Node* ptr=(*head);
        if (ptr->next!=NULL){
            while (ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->prev->next=NULL;
            delete ptr;

        }


    }

}



// returns the node containing a given data.

Node* Search(Node* head, int data){
    Node* ptr=head;
    while (ptr!=NULL){
        if (ptr->Data==data){
            return ptr;
        }
        ptr=ptr->next;

    }

}

// Delete node containing a given data.

void Deletenode(Node** head,int data){
    Node* ptr=Search((*head),data);
    if (ptr==(*head)){
        Pop(head);
    }
    else if (ptr->next==NULL && ptr->prev!=NULL){
        DeleteLast(head);
    }else{
      ptr->next->prev=ptr->prev;
      ptr->prev->next=ptr->next;
      delete ptr;
    }

}


void Print(Node* head){
    Node* ptr=head;
    Node* last;
    cout<<"Traversal in forward direction"<<endl;
    while (ptr!=NULL){
        cout<<ptr->Data<<' ';
        last=ptr;
        ptr=ptr->next;
    }
    cout<<"\n"<<"Traversal in reverse direction"<<endl;
    while (last!=NULL){
        cout<<last->Data<<' ';
        last=last->prev;
    }
}
