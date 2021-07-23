#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define lli long long int
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define mp make_pair
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b)/__gcd(a, b)
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
using namespace __gnu_pbds;
 typedef tree<lli, null_type, less_equal<lli>, rb_tree_tag,
 tree_order_statistics_node_update>
 ordered_set;
 
// *s.find_by_order(p)          returns the value of pth largest starting from 0 
// s.order_of_key(p)            returns no. of items that are strictly < p 
// s.erase(s.upper_bound(p))    p is an element in a multiset and this deletes only one occurance of p
 
const lli N = 3e5+2;
const lli INF = 1e9+9;
const lli mod = 998244353;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x)
{
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
        return;
    }

    Node* ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new_node;
    return;
}

void printList()
{
    Node* ptr = head;
    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    

}
