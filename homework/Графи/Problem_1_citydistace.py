pip install networkx matplotlib
import networkx as nx
import matplotlib.pyplot as plt

# Створюємо граф
G = nx.Graph()

# Додаємо ребра (місто1, місто2, відстань)
G.add_weighted_edges_from([
    ("Київ", "Житомир", 140),
    ("Київ", "Чернігів", 130),
    ("Житомир", "Рівне", 190),
    ("Рівне", "Львів", 210),
    ("Чернігів", "Суми", 180),
    ("Суми", "Харків", 170),
    ("Київ", "Полтава", 340),
    ("Полтава", "Харків", 150)
])

# Малюємо граф
pos = nx.spring_layout(G, seed=42)
nx.draw(G, pos, with_labels=True, node_color="lightblue", node_size=2000, font_size=10, font_weight="bold")
nx.draw_networkx_edge_labels(G, pos, edge_labels=nx.get_edge_attributes(G, 'weight'))

plt.title("Карта міст — граф з вагами")
plt.show()

# Знаходимо найкоротший шлях між Києвом і Харковом
shortest_path = nx.shortest_path(G, source="Київ", target="Харків", weight='weight')
distance = nx.shortest_path_length(G, source="Київ", target="Харків", weight='weight')

print(f"Найкоротший шлях від Києва до Харкова: {' → '.join(shortest_path)}")
print(f"Загальна відстань: {distance} км")
