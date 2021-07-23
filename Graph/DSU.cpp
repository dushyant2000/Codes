#include<bits/stdc++.h>
using namespace std;

class DSU
{
	public:
		int *size, *parent, n;		//size stores the deapth of the tree/set
		DSU(int n)					//parent stores the representative of the tree(root node)/set
		{
			size = new int[n+1];
			parent = new int[n+1];
			this->n = n;
			make_set();
		}
		
		void make_set()				//initialization
		{
			for(int i=1;i<=n;i++)
			{
				parent[i]=i;
				size[i]=1;
			}
		}

		int find(int x)				//finds a parent pointer to given element
		{
			if(parent[x]==x)
				return x;
			return parent[x] = find(parent[x]);
		}

		bool merge(int x, int y)		//perfroms union operation b/w a set containing x and a set containing y
		{
			x = find(x);
			y = find(y);

			if(x==y)
				return false;
			if(size[x]<size[y])			//bcz we want to minimize the deapth of the tree
			{
				swap(x, y);
			}
			parent[y]=x;
			size[x]+=size[y];
			return true;
		}
};


int main()
{
	DSU ds(5);
	ds.merge(1, 3); 
    ds.merge(5, 3); 
    ds.merge(4, 2); 

    if (ds.find(5) == ds.find(1)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    if (ds.find(2) == ds.find(1)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 

    cout<<"Parent pointer:- ";
    for(int i=0;i<ds.n;i++) cout<<ds.parent[i]<<" ";
    cout<<endl;
	return 0;
}