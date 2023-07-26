def canVisitAllRooms(rooms):
    visited = [] # 5번방 방문 안했네? => False //True

    def dfs(v):
        visited.append(v)
        for next_v in rooms[v]:
            if next_v not in visited:
                dfs(next_v)
        pass

    dfs(0)
    
    if len(visited) == len(rooms): return True
    else: return False
    



rooms = [[1,3],[2,4],[0],[4],[],[3,4]]
print(canVisitAllRooms(rooms))