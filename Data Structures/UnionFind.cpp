#include "bits/stdc++.h"

using namespace std;

//Orden( E*log(N) );

int etiqueta[100],numset;

void Init(int n){
    for(int i=0; i<n; i++) etiqueta[i]=i;
    numset=n;
}

int Find(int x){
    return etiqueta[x]==x ? x : etiqueta[x]=Find(etiqueta[x]);
}

void Union(int a,int b){
    if(Find(a)==Find(b))numset--;
    etiqueta[Find(a)]=Find(b);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    Init(n);
    int a,b;
    while(m--){
        scanf("%d %d",&a, &b);
        Union(a-1,b-1);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a, &b);
        if(Find(a-1)==Find(b-1)){
            printf("el nodo %d esta conectado con el nodo %d\n", &a, &b);
        }else{
            printf("el nodo %d esta conectado con el nodo %d\n", &a, &b);
        }
    }
    return 0;
}
