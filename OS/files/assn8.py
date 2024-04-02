class FIFO:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = []

    def page_in(self, page):
        if page not in self.queue:
            if len(self.queue) == self.capacity:
                self.queue.pop(0)
            self.queue.append(page)

    def __repr__(self):
        return str(self.queue)


class LRU:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = []

    def page_in(self, page):
        if page in self.queue:
            self.queue.remove(page)
        elif len(self.queue) == self.capacity:
            self.queue.pop(0)
        self.queue.append(page)

    def __repr__(self):
        return str(self.queue)


class LFU:
    def __init__(self, capacity):
        self.capacity = capacity
        self.page_freq = {}
        self.queue = []

    def page_in(self, page):
        if page in self.page_freq:
            self.page_freq[page] += 1
        else:
            if len(self.page_freq) == self.capacity:
                least_freq_page = min(self.page_freq, key=self.page_freq.get)
                del self.page_freq[least_freq_page]
                self.queue.remove(least_freq_page)
            self.page_freq[page] = 1
        self.queue.append(page)

    def __repr__(self):
        return str(self.queue)


# Example usage
fifo = FIFO(3)
fifo.page_in(1)
fifo.page_in(2)
fifo.page_in(3)
print("FIFO:", fifo)

lru = LRU(3)
lru.page_in(1)
lru.page_in(2)
lru.page_in(3)
print("LRU:", lru)

lfu = LFU(3)
lfu.page_in(1)
lfu.page_in(2)
lfu.page_in(1)
lfu.page_in(3)
print("LFU:", lfu)
