
#include <iostream>

using namespace std;
//test modified file for git
//second modify
/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    //sort in O(nlog n) time

    ListNode *findMiddle(ListNode *l){
        ListNode *middle=l;
        ListNode *tail=l;
        while(tail->next){

            if(tail->next->next){
                tail=tail->next->next;
                middle=middle->next;
            }
            else
                break;
        }
        //cout<<middle->val<<endl;
        return middle;
    }
    ListNode *mergeList(ListNode *l1,ListNode *l2){
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode *p1=l1;
        ListNode *p2=l2;
        ListNode *resList=new ListNode(0);
        ListNode *r=resList;
        while(p1!=NULL && p2!=NULL){
            if(p1->val <= p2->val){
                r->next=new ListNode(p1->val);
                r=r->next;
                p1=p1->next;
            }
            else{
                r->next=new ListNode(p2->val);
                r=r->next;
                p2=p2->next;
            }


        }
        while(p1){

            r->next=new ListNode(p1->val);
            r=r->next;
            p1=p1->next;
        }
        while(p2){
            r->next=new ListNode(p2->val);
            r=r->next;
            p2=p2->next;
        }
        return resList->next;


    }
//binary sort
    ListNode *sortList(ListNode *head) {
        if( head==NULL || head->next==NULL)
            return head;
        ListNode *middle=findMiddle(head);
        auto left=head;
        auto right=middle->next;
        middle->next=NULL;
        left=sortList(left);


        right=sortList (right);

        return mergeList(left,right);
    }

    //insertion sort

    ListNode *insertionSort(ListNode *head){
        if(!head)
            return head;

        auto t=head->next;
        auto tail=head;
        while(t){
            if(t->val >= tail->val){//insert behand the sorted tail
                tail=t;
                t=t->next;
                continue;
            }
            //
            tail->next=t->next;
            t->next=NULL;

            if(head->val >=t->val){

                t->next=head;
                head=t;
                t=tail->next;
                continue;
            }
            auto p=head;
            while(p->next){
                if(p->next->val > t->val){
                    t->next=p->next;
                    p->next=t;
                    t=tail->next;
                    break;


                }
                p=p->next;


            }


        }
        return head;
    }


};

int main()
{
    ListNode *a= new ListNode(3);
    ListNode *b= new ListNode(0);
    ListNode *c= new ListNode(9);
    ListNode *d= new ListNode(9);
    a->next=b;
    b->next=c;
    c->next=d;
    Solution s;
    a=s.insertionSort(a);
    auto p=a;
    while(p){
        cout<<p->val;
        p=p->next;

    }
    //cout << "Hello world!" << endl;
    return 0;
}
