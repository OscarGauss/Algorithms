#include "bits/stdc++.h"

using namespace std;

#define Right(n) (2*n)
#define Left(n) (2*n+1)
#define Mid(i,j) ( (i+j)/2 )
vector<int> Tree(1048576+1);
vector<int> A(100000);

//Arbol [0,N) desde 1 hasta N; Intervalo [p,q) desde p+1 hasta q;
//Vector A comienza desde 1 hasta N;

int ForceBrute(int i,int j){
	int sum=0;
	for(int l=i; l<=j; l++){
		sum+=A[l];
	}
	return sum;
}

void BuildTree(int node,int p,int q){
	if(p+1==q){
		Tree[node] = A[q];
		return ;
	}
	BuildTree(Left(node) , p, Mid(p,q));
	BuildTree(Right(node), Mid(p,q), q);
	Tree[node] = Tree[Left(node)]+Tree[Right(node)];
}

void Update(int node, int p, int q, int index, int value){
	if(p+1==q){
		Tree[node] = A[q] = value;
		return ;
	}
	if(index < Mid(p,q))
		Update(Left(node), p, Mid(p,q), index, value);
	else
		Update(Right(node), Mid(p,q), q, index, value);
	Tree[node]=Tree[Left(node)] + Tree[Right(node)];
}

int Query(int node, int p,int q, int l, int r){
	//l,r fuera de rango  cuando l>=q or r<=p
	if(l >= q or r <= p ) return 0;
	if(p >= l and q <= r) return Tree[node];
	return Query(Left(node), p, Mid(p,q), l,r) + Query(Right(node), Mid(p,q), q, l,r);
}

int main(){
	int n,m,x,y;
	while(scanf("%d\n",&n)!=EOF){
		for(int i=1; i<=n; i++)
	 		scanf("%d\n",&A[i]);
	 	BuildTree(1, 0, n);
		//Dado un rango 4-5 => [3,5)
		printf("%d\n",Query(1, 0, n, 4-1, 5));
		//Dado un rango 5-15 => [4,15)
		printf("%d\n",Query(1, 0, n, 5-1, 15));
		cin>>m;
		while(m--) {
			//El vector comienza desde 1 Tree mandar [index
		    scanf("%d %d", &x, &y);
		    Update(1, 0, n, x-1, y);
		    for(int i=1; i<n*4; i++)cout<<Tree[i]<<" ";cout<<endl;
		}
	}
	return 0;
}