//Bausteine für Search in Arrays
const int ARR_LENGTH = 4;

typedef struct node_arr{
    int *arr;
    struct node_arr *next;
}node_arr;

node_arr *create_node_arr(int arr[]){
    node_arr *new = malloc(sizeof(new));
    int new_arr[ARR_LENGTH];
    for(int i = 0; i < ARR_LENGTH; i++){
        new_arr[i] = arr[i];
    }
    new->arr = new_arr;
    new->next = 0;
    return new;
}

void push(node_arr **root, int x[]){
    node_arr *p = *root;
    node_arr *new = create_node_arr(x);
    new->next = p;
    *root = new;
}

int pop(node_arr **root,int out[]){
    node_arr *p = *root;
    if(p==0){
        return -1;
    }
    out = p->arr;
    *root = p->next;
    free(p);
    return 0;
}

int is_equal_arr(int arr[], int arr2[]){
    int equal = 1;
    for(int i = 0; i < ARR_LENGTH; i++){
        if(arr[i] != arr2[i]){
            return 0;
        }
    }
    return equal;
}

int linsearch_dynamic_list(node_arr **root, int x[]){
    int index = -1;
    node_arr *p = *root;
    int i = 0;
    while (p!=0){
        if(is_equal_arr(p->arr,x)==1){
            return i;
        }
        i++;
    }
    return index;
}


int linsearch_arr(int arr[],int length, int x){
    int index = -1;
    for(int i = 0; i < length; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return index;
}