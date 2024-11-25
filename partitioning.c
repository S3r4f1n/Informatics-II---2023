//Bausteine für Quicksort
void swap(int A[], int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}



int hoare_partitioning(int A[], int l, int r){/*l first elem r last elem*/
    int pivot = A[r];
    l--; /*necesarry because of repeat loops*/
    r++;
    while (l<r){
        l++;/*makes shure to not get stuck on elem = pivot*/
        while (A[l]<pivot){ /*getting first elem >= pivot*/
            l++;
        }
        r--;/*makes shure to not get stuck*/
        while (A[r]>pivot){ /*getting last elem <= pivot*/
            r--;
        }
        if(l<r){
            swap(A,l,r);
        }else{
            return l;/*somwehrer but not on the first*/
        }
    }
}

void quicksort1(int arr[],int l, int r){/*l first elem r last elem*/
    if (l<r){/*at least size of two*/
        int m = hoare_partitioning(arr,l,r); /*splitting into small and big and returning beginning of big part*/
        quicksort1(arr,l,m-1);
        quicksort1(arr,m,r);
    }
}

int lomuto_partitioning(int A[],int l,int r){/*l first elem r last elem*/
    int pivot = A[r];
    int small = l; /*one after the smaller the piivot part*/
    for(int i = l; i < r;i++){
        if(A[i]<pivot){
            swap(A,small,i);
            small += 1;
        }
    }
    swap(A,small,r);
    return small; /*middle of partitioning*/
}

void quicksort2(int arr[], int l , int r){/*l first elem r last elem*/
    if (l<r){/*at least size of two*/
        int m = lomuto_partitioning(arr, l , r); /*splitting into large small and getting the splitting location*/
        quicksort2(arr,l,m-1);
        quicksort2(arr,m+1,r);
    }
}