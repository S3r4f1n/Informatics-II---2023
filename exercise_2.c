
void beam(x, k){
    bandwith_queue = initQueue();
    rest_queue = initQueue();
    x.visited = 1;
    enQueue(bandwith_queue, x);
    while (bandwith_queue != 0 or rest_queue != 0) do
        if bandwith_queue != 0 do
            current = deQueue(bandwith_queue);
        else    
            current = deQueue(rest_queue)
        current.visited = 1;
        print(current.key);
        i = 0
        for adj in x.adj do
            if adj.visited == 0 and i < 2 do
                enQueue(bandwith_queue, adj)
            elif adj.visited == 0 do
                enQueue(rest_queue,adj)
