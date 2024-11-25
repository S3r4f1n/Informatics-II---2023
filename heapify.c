//Bausteine für Heapsort
int child_left(int i){
    return 2*(i+1)-1;
}

int child_right(int i){
    return 2*(i+1)+1-1;
}

void swap(int A[],int a, int b){
    int t = A[a];
    A[a] = A[b];
    A[b] = t;
}

void heapify(int A[],int i,int s){/* i current element, s size of heap*/
    int m = i;
    int l = child_left(i);
    int r = child_right(i);
    if(l<s && (A[m]<A[l])){
        m = l;
    }
    if(r<s && (A[m]<A[r])){
        m = r;
    }
    if(m!=i){
        swap(A,m,i);
        heapify(A,m,s);
    }
}

void build_heap(int A[],int s){
    for(int i = s/2;i<s;i++){
        heapify(A,s-i-1,s);
    }
}
