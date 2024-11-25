queue;
void enqueue(int x);
int dequeue();
/*don't include above*/

const int m = 10;

void rec_dfs(int mat[m][m], int current, int visited[]){
    /*arriving on node current*/
    visited[current] = 1;
    for(int i = 0; i <m ; i++){
        if(mat[current][i] == 1 && visited[i] == 0){

            rec_dfs(mat,i,visited);
        }
    }
    /*leaving node current*/
}

void dfs(int mat[m][m], int start){
    int visited[m];
    for(int i = 0; i < m; i++){
        visited[i] = 0;
    }
    rec_dfs(mat,start,visited);/*initial run*/
    for(int i = 0; i <m; i++){/*collecting al not visited nodes*/
        if(visited[i] == 0){
            rec_dfs(mat,i,visited);
        }
    }
}

void bfs(int mat[m][m], int start){
    int visited[m];
    int current;
    for(int i = 0; i < m; i++){
        visited[i] = 0;
    }
    visited[start] = 1;
    enqueue(start);
    while (queue != 0){
        current = dequeue();
        /*arriving on node current*/
        for(int i = 0; i < m; i++){
            if(mat[current][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}