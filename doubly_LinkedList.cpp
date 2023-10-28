#include <istream>
using namespace std;
class node {
    public:
    int value;
    node*next;
    node*pre;
    node(int value)
    {
        this->value=value;
        pre=nullptr;
        next=nullptr;
    }
};
class DLL{
    private:
    node*head;
    node*tail;
    int length;
    public:
    DLL(int value)
    {
        node *newnode=new node(value);
        head=newnode;
        tail=newnode;
        length=1;
    }
    ~DLL()
    { node *temp=head;
        while(head)
        {
          head=head->next;
          delete temp;
          temp=head;
        }
    }
    void print_DLL(){
        node*temp=head;
        while(temp)
        {   printf("%d\n",temp->value);
            temp=temp->next;
        }
    }
    void deleteFisrt()
    {
        node *temp=head;
        if (length==0)     {return ;   }
        if (length==1){
         head=nullptr;
         tail=nullptr;
        }
        else{
            head=head->next;
            head->pre=nullptr;
        }
    delete temp;
    length--;
    }
    void deleteLast()
    {node *temp=tail;
        if (length==0)
        {return;}
        if (length==1)
        {
           
            head=nullptr;
            tail=nullptr;
        }
        else{
            
            tail=tail->pre;
            tail->next=nullptr;
        }
        delete temp;
        length--;
    }
    void prepend(int value)
    {
        node*newnode=new node(value);
        if(length==0)
        {
            head=newnode;
            tail=newnode;
        }
        else{
            newnode->next=head;
            head->pre=newnode;
            head=newnode;
        }
        length++;

    } 
    void append (int value)
    { node *newnode=new node(value);
        if (length==0)
        {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->pre=tail;
            tail=newnode;
           
        }
        length++;
    }
    node* get(int index)
    {
        node* temp=head;
        if (index>=0 || index<=length)
        {
         if (index==0)
         {return head;}
         if (index==length-1)
         {return tail;}
       else {
        for (int i=0; i<index;i++)
        {
            
           temp= temp->next;
        }
        return temp;
       }
       
    }
    }
    bool set (int index,int value)
    { if(index>=0 || index<=length){
    node *temp=get(index);
    temp->value=value;
    return true;
    }
    return false;
    }
    bool insert(int index,int value)
    {   
        if(index>=0 || index<=length)
        {
         if (index==0)
         {
            prepend(value);
            return true;
         }
         if(index==length)
         {
            append(value);
            return true;
         }
         else{
            node *newnode= new node(value);
            node * prev=get(index-1);
            node* temp=prev->next;
            prev->next=newnode;
            newnode->pre=prev;
            newnode->next=temp;
            temp->pre=newnode;
            length++;
            return true;
         }
         return false;
        }
    }
    void deleteNode(int index)
    {
        if (index>=0|| index<=length)
        {
            if(index==0)
            {
                return deleteFisrt();
            }
            if(index==length-1)
            {return deleteLast();}
            else{
                node*temp=get(index);
                node*before=temp->pre;
                node*after=temp->next;
                before->next=after;
                after->pre=before;
                delete temp;
                length--;
            }
        }
    }
    void get_tail()
    {
        printf("%d\n",tail->value);
    }
    void get_length()
    {
        printf("%d\n",length);
    }

};
int main()
{
 DLL *myDLL=new DLL(21);
myDLL->append(34);
myDLL->append(32);
myDLL->append(39);
myDLL->print_DLL();
//printf("%d\n",myDLL->get(3)->value);
myDLL->insert(4,89);
myDLL->print_DLL();
myDLL->deleteNode(4);
myDLL->print_DLL();

}