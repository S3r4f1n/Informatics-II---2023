
// Das sind C types. Geht in die Richtung von klassen. Die umfassen jedoch keine Methoden nur variablen.
//typische datenstruktur um Ketten zu bilden. Node speichert ein Integer und ein Link (pointer) zu einer weiteren node.
typedef struct node
{
    int val; //einfacher integer
    struct node *next; //pointer, also eine Adresse/Pointer die zu einem Datentyp "struct node" zeigt.
}node;

node *create_node(int x){//Funktion die eine Adresse/Pointer zu einer "struct node" zurück gibt. (node = struct node, wegen typedef von oben)
    node *p = malloc(sizeof(p));//memory Management :)
    p->next = 0;
    p->val = x;
    return p;
}
/*queue-----------------------------------------------*/
// Funktionen um eine globale Queue mit Anfangs-Node queue zu erstellen. 
node *queue = 0; //node *queue = NULL; würde dasselbe machen. NULL pointer sind wichtig in C
node *end_queue = 0;


void enqueue(int x){
    node *p = create_node(x); 
    if(queue == 0){
        queue = p;
    }else{
        end_queue->next = p;
    }
    end_queue = p;
}

int dequeue(){
    int out = queue->val;
    node *next = queue->next;

    free(queue); //memory Management :)

    queue = next;
    return out;
}
/*stack-----------------------------------------------*/
//stack und queue sind sehr ähnlich.
//queue = first in first out. Wer zuerst ansteht darf als erstes rein.
//stack = first in last out. In einem Buss müssen zuerst die aussteigen die zuletzt rein sind, damit die anderen platz haben um aus zu steigen.
node *stack = 0;


void push(int x){
    node *p = create_node(x); 
    p->next = stack;
    stack = p;
}

int pop(){
    int out = stack->val;
    node *next = stack->next;

    free(stack);

    stack = next;
    return out;
}

/*bfs dfs----------------------------------------------*/
//das hier ist ein bisschen advanced, gegen ende des Semesters wird das wichtig. bfs und dfs steht für breadth first search und depth first search. 
//Die Grund Idee ist, dass man einen directed Graph hat und in diesem directed Graph die Nachbarn absucht. Entweder alle nahen zuerst. Oder die Nachbarn der Nachbarn zuerst. 
//In beiden verfahren werden alle Nodes erreicht.

const int m = 10;
int COUNT = 0;
static int OUTPUT[10];
static int ARRIVE[10];
static int LEAVE[10];

//eine rekursive Implementierung des depth first search. Der Graph wird als adjecancy-Matrix (mat) dargestellt. Eine node wird durch einen simplen Integer.
// die globalen Variablen von oben werden benützt.
void rec_dfs(int mat[m][m], int current, int visited[]){
    /*arriving on node current*/
    ARRIVE[current] = COUNT;
    COUNT++;
    visited[current] = 1;
    for(int i = 0; i <m ; i++){
        if(mat[current][i] == 1 && visited[i] == 0){

            rec_dfs(mat,i,visited);
        }
    }
    /*leaving node current*/
    LEAVE[current] = COUNT;
    COUNT++;
}

//wrapper für die rekursive Implementierung
void dfs(int mat[m][m], int start){
    int visited[m];
    for(int i = 0; i < m; i++){//erstellen des visited array
        visited[i] = 0;
    }

    rec_dfs(mat,start,visited);/*main run - alle erreichbaren nodes werden besucht*/

    for(int i = 0; i <m; i++){/*collecting al not visited nodes*/
        if(visited[i] == 0){
            rec_dfs(mat,i,visited);
        }
    }
}

//Eine iterative breath first search Implementation
//note: wechselt man im folgenden code die queue mit einem stack aus, hat man einen iterativen depth first search.
//im Gegensatz zum algorithmus oben sammelt dieser hier die nicht verbunden nodes nicht ein. Die werden nie besucht.
void bfs(int mat[m][m], int start){
    //setup--------------------
    int visited[m];
    int current;
    for(int i = 0; i < m; i++){
        visited[i] = 0;
    }
    visited[start] = 1;
    enqueue(start);
    //search------------------
    while (queue != 0){
        current = dequeue();
        /*arriving on node current*/
        OUTPUT[current] += 1;
        for(int i = 0; i < m; i++){//Sammeln aller Nachbarn
            if(mat[current][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

//black magic: Ne da hab ich probiert den rekursiven Algorithmus mit stacks zu implementieren, da dies immer möglich sein sollte 
//Ist aber nicht Fokus des Kurses und hab mir darum nicht die Zeit genommen die Fehler zu finden.
void stack_dfs(int mat[m][m], int start){/*buggy*/
    int visited[m];
    int current;
    int next;
    for(int i = 0; i < m; i++){
        visited[i] = 0;
    }
    
    current = start;
    push(current);
    /*arriving on node current*/
    visited[current] = 1;
    ARRIVE[current] = COUNT;
    COUNT++;
    while(0 == 0){        
        next = -1;
        for(int i = 0; i < m; i++){
            if(mat[current][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                push(i);
                next = i;
            }
        }
        current = next;
        if(current == -1){
            current = pop();
            /*Leaving node current*/
            LEAVE[current] = COUNT;
            COUNT++;
        }else{
            /*arriving on node current*/
            visited[current] = 1;
            ARRIVE[current] = COUNT;
            COUNT++;
        }
        if(stack == 0){
            break;
        }
    }
}

//main Function wird ausgeführt nach Compilen. ähnlich wie in Java. Diese hier macht nichts
void main(){
    int mat[10][10] ={{0,1,0,0,0,0,1,0,0,0},
                      {0,0,1,0,0,0,0,0,0,0},
                      {0,0,0,1,0,0,0,0,0,0},
                      {0,0,0,0,1,0,0,0,0,0},
                      {0,0,0,0,0,1,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,1,0,0},
                      {0,0,0,0,0,0,0,0,1,0},
                      {0,0,0,0,0,0,0,0,0,1},
                      {0,0,0,0,0,0,0,0,0,0}
                      };
    for(int i = 0; i <m ; i++){
        OUTPUT[i] = 0;
    }
    stack_dfs(mat,0);
    int x = 1;

}