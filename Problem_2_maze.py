from collections import deque

with open("maze.txt") as f:
    maze = [list(line.strip()) for line in f]

#Створюємо словник для збереження координат ключових точок
points = {}
for y, row in enumerate(maze):
    for x, val in enumerate(row):
        if val.isalpha():
            points[val] = (x, y)
#Функція для знаходження шляху між двома точками за допомогою пошуку в ширину

def bfs(start, goal, maze):
    queue = deque([start])
    visited = {start: None}
    
    while queue:
        x, y = queue.popleft()
        if (x, y) == goal:
            break
        
        for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
            nx, ny = x + dx, y + dy
            if maze[ny][nx] != '#' and (nx, ny) not in visited:
                visited[(nx, ny)] = (x, y)
                queue.append((nx, ny))
                
    # відновлюємо шлях
    path = []
    current = goal
    while current:
        path.append(current)
        current = visited.get(current)
    path.reverse()
    return path

#Знаходимо шлях між УСІМА ключовими точками

order = ['A', 'B', 'C']
total_path = []

print(" Довжини шляхів:")
total_length = 0
full_path = []

for i in range(len(order) - 1):
    start = points[order[i]]
    end = points[order[i + 1]]
    segment = bfs(start, end, maze)
    segment_length = len(segment) - 1 # бо перша точка не рахується
    print(f"- {order[i]} → {order[i + 1]}: {segment_length} кроків")
    total_length += segment_length
    full_path += segment[1:] # додаємо, пропускаючи повтор точки

print(f"- Загальна: {total_length} кроків\n")


#Виводимо загальний шлях
for x, y in total_path:
    if maze[y][x] == '.':
        maze[y][x] = '*'

for row in maze:
    print(''.join(row))
