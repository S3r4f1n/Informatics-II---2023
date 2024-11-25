#include <stdio.h>

const int n = 10; /*size of r1*/
const int m = 10; /*size of r2*/
static int arr[n+m];


typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} node;

index = 0;

void infix_run(node *head){
    if(head == 0){
        return;
    }
    infirx_run(head->left);
    arr[index] = head->val;
    index++;
    infirx_run(head->right);
}

void print_arr(){
    int index_n = 0;
    int index_m = n;
    for(int i = 0; i < m + n; i++){
        if(index_m >= (m+n) || (index_n < n && arr[index_n] < arr[index_m])){ /*printing from the first tree if smaller and making shure no out of scope error occure*/
            printf("%d, ",arr[index_n]);
            index_n++;
        }else{
            if(index_m < m+n){/*printing from the second tree if bigger and making shure no out of scope error occures*/
                printf("%d, ",arr[index_m]);
                index_m++;
            }
        }
    }
}

void main(){
    infirx_run(r1);
    infirx_run(r2);
    print_arr();
}
