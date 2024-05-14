class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.count = 1
        self.prev = None
        self.next = None

class DoubleLinkedList:
    def __init__(self):
        self.head = Node(None, 'head')
        self.tail = Node(None, 'tail')
        self.head.next = self.tail
        self.tail.prev = self.head
    
    def insert_at_head(self, node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node
    
    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
    
    def is_empty(self):
        return self.head.next == self.tail

class LFUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.min_count = 0
        self.node_map = {}
        self.freq_map = {}

    def get(self, key):
        if key not in self.node_map:
            return -1
        node = self.node_map[key]
        self._update_node(node)
        return node.value

    def put(self, key, value):
        if self.capacity == 0:
            return
        if key in self.node_map:
            node = self.node_map[key]
            node.value = value
            self._update_node(node)
        else:
            if self.size == self.capacity:
                self._evict_node()
            node = Node(key, value)
            self.node_map[key] = node
            self.freq_map.setdefault(1, DoubleLinkedList()).insert_at_head(node)
            self.min_count = 1
            self.size += 1

    def _update_node(self, node):
        count = node.count
        self.freq_map[count].remove(node)
        if count == self.min_count and self.freq_map[count].is_empty():
            self.min_count += 1
        
        node.count += 1
        self.freq_map.setdefault(node.count, DoubleLinkedList()).insert_at_head(node)

    def _evict_node(self):
        oldest = self.freq_map[self.min_count].tail.prev
        self.freq_map[self.min_count].remove(oldest)
        del self.node_map[oldest.key]
        self.size -= 1


cache = LFUCache(2)
cache.put(1, 1)
cache.put(2, 2)
print(cache.get(1))  
cache.put(3, 3)      
print(cache.get(2))  
print(cache.get(3))  
cache.put(4, 4)
cache.put(5, 5)
print(cache.get(4))  
print(cache.get(5))  
# The LFU class initializes with dictionaries for storing entries and their frequencies, a minimum frequency tracker, and a capacity limit for the cache.
# Retrieves the value for a given key, updates its frequency by moving the key to the next frequency list, and adjusts the minimum frequency if necessary.
# Inserts or updates a key's value, handling eviction by removing the least frequently used item if the cache is full, then recalibrates the frequency.
# Targets the least frequently used items for removal by accessing the list at the current minimum frequency, ensuring efficient cache space management.
# Maintains lists of keys at each frequency level, allowing the cache to quickly adapt and reorganize as different keys are accessed or added.
# evicts key is to remove a key from a cache due to space constraints when a new item needs to be added. 