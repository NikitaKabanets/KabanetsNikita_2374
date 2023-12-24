class Graph:
    def __init__(self, vertices):

        self.V = vertices
        self.graph = []

        for i in range(vertices):

            list = []

            for i in range(vertices):
                list.append(0)
            self.graph.append(list)

    def add_edge(self, u, v, w):

        self.graph[u][v] = w
        self.graph[v][u] = w


def insertionSort(arr):
    n = len(arr)
    if n <= 1:
        return
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

    return arr

def find(parent, i):
    if parent[i] == i:
        return i
    return find(parent, parent[i])


def union(parent, rank, x, y):
    root_x = find(parent, x)
    root_y = find(parent, y)

    if rank[root_x] < rank[root_y]:
        parent[root_x] = root_y
    elif rank[root_x] > rank[root_y]:
        parent[root_y] = root_x
    else:
        parent[root_y] = root_x
        rank[root_x] += 1


def print_result(result, total_weight):
    for edge in result:
        edges = [chr(ord('A') + a) for a in edge]
        edges_out = ' '.join(edges)
        print(edges_out)
    print(total_weight)


def kruskal_mst(graph):
    edges = []
    for i in range(graph.V):
        for j in range(i + 1, graph.V):
            if graph.graph[i][j] != 0:
                edges.append((graph.graph[i][j], i, j))
    edges = insertionSort(edges)
    parent = [i for i in range(graph.V)]
    rank = [0] * graph.V
    result = []
    total_weight = 0
    for edge in edges:
        weight, u, v = edge
        root_u = find(parent, u)
        root_v = find(parent, v)
        if root_u != root_v:
            result.append((u, v))
            total_weight += weight
            union(parent, rank, root_u, root_v)
    return result, total_weight

if __name__ == "__main__":
    file = open("matrix.txt", "r")
    lines = file.readlines()

    vertices = len(lines[0].split())
    graph = Graph(vertices)

    for i in range(vertices):
        edge_values = list(map(int, lines[i + 1].split()))
        for j in range(vertices):
            graph.add_edge(i, j, edge_values[j])

    result, total_weight = kruskal_mst(graph)
    print_result(result, total_weight)

