#include<iostream>
#include<cstdlib>

using namespace std;

class Doubly_list
{
private:
    typedef struct node
    {
      int key;
      int val;
      node* previous = NULL;
      node* next = NULL;
    }* nodeptr;

    nodeptr head;
    nodeptr curr;
    nodeptr temp;

    nodeptr NodeExist(int k)
    {
        curr = head;
        while(curr != NULL)
        {
            if(curr ->key == k)
            {
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }


public:
    Doubly_list()
    {
        head = NULL;
        curr = head;
        temp = head;
    }


    void AppendNode(int k ,int data)
    {

        if(NodeExist(k) !=NULL)
        {
            cout<<"node has existed"<<endl;
            return ;
        }

        curr = head;
        temp = head;
        nodeptr n = new node;
        n->key = k;
        n-> val = data;

        if(curr == NULL)
        {
            head = n;
            return ;
        }

        while(curr!=NULL)
        {

            temp = curr;
            curr = curr->next;
        }
        n -> previous = temp;
        temp -> next = n;

    }

    void PrependNode(int k, int data)
    {
        if(NodeExist(k) !=NULL)
        {
            cout<<"node has existed"<<endl;
            return ;
        }

        nodeptr n = new node;
        n->key = k;
        n->val = data;
        head->previous = n;
        n-> next = head;
        head = n;
    }

    void InsertNode(int k,int addkey,int data)
    {
        nodeptr n = NodeExist(k);
        nodeptr anode = new node;
        anode->key = addkey;
        anode->val = data;
        if(n ==NULL)
        {
            cout<<"node k not in list"<<endl;
            return ;
        }
        else
        {
            if(n->next == NULL)
            {
                AppendNode(addkey,data);
                return;
            }
            else
            {
                anode->previous = n;
                anode->next = n->next;
                n->next = anode;
                return;
            }

        }
    }

    void DeleteNode(int k)
    {
        if(NodeExist(k) ==NULL)
        {
            cout<<"node not in list"<<endl;
            return ;
        }
        else
        {
            nodeptr n = NodeExist(k);
            if(n == head)
            {
                head = NULL;
                delete n;
                return;
            }
            n->previous->next = n->next;
            if(n->next!=NULL)
            {
                n->next->previous = n->previous;
            }
            delete n;
        }
    }

    void UpdateNode(int k,int data)
    {
        nodeptr n = NodeExist(k);
        if(n !=NULL)
        {
            n -> val = data;
        }
        else
        {
            cout<<"node not in list"<<endl;
        }

    }

    void PrintList()
    {

        curr = head;
        while(curr!=NULL)
        {
            cout<<"key: "<<curr->key<<" val: "<<curr->val<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};

int main()
{
    Doubly_list double_list = Doubly_list();
    double_list.AppendNode(3,7);
    double_list.PrintList();
    double_list.AppendNode(5,12);
    double_list.PrintList();
    double_list.UpdateNode(5,200);
    double_list.PrintList();
    double_list.PrependNode(8,150);
    double_list.PrintList();
    double_list.DeleteNode(3);
    double_list.PrintList();
    double_list.InsertNode(8,9,7);
    double_list.PrintList();

    return 0;
}
