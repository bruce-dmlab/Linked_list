#include<iostream>
#include<cstdlib>

using namespace std;

class List
{
private:
        typedef struct node
        {
            int val;
            node* next = NULL;
        }* nodeptr;

        nodeptr head;
        nodeptr curr;
        nodeptr temp;

public:
    List()
    {
        head = NULL;
        curr = head;
        temp = head;
    }


    void InsertNode(int insert_data)
    {
        nodeptr n = new node;
        n -> val = insert_data;
        curr = head;

        if(curr == NULL)
        {
            head = n;
        }
        else
        {
            while(curr->next!=NULL)
            {
                curr = curr -> next;
            }
            curr -> next = n;
        }
    }

    void PrintNode()
    {
        curr = head;
        while(curr!=NULL)
        {
            cout<<curr ->val<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }

    void DeleteNode(int delete_data)
    {
        curr = head;
        temp = head;
        while(curr !=NULL && curr->val != delete_data)
        {
            temp = curr;
            curr = curr->next;
        }

        if(curr == NULL)
        {
            cout<<delete_data<<" not in list"<<endl;
        }
        else
        {

            nodeptr n = curr;
            curr = curr->next;
            if(n == head)
            {
                head = NULL;
            }
            temp ->next = curr;
            delete n;
        }
    }

};


int main()
{
    List single_list = List();
    single_list.InsertNode(5);
    single_list.PrintNode();
    single_list.DeleteNode(5);
    single_list.InsertNode(3);
    single_list.InsertNode(8);
    single_list.PrintNode();
    return 0;
}
