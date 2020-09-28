class HashMap:
    def __init__(self):
        self.MAX = 100
        self.arr = [[] for _ in range(self.MAX)]

    def get_hash(self, key):
        hash = 0
        for char in key:
            hash += ord(char)
        return hash % self.MAX
    
    def __setitem__(self, key, value):
        h = self.get_hash(key)
        found = False
        for index, element in enumerate(self.arr[h]):
            if len(element) == 2 and element[0] == key:
                self.arr[h][index] = (key, value)
                found = True
                break
        if not found:
            self.arr[h].append((key, value))

    def __getitem__(self, key):
        h = self.get_hash(key)
        for element in self.arr[h]:
            if element[0] == key:
                return element[1]
    
    def __delitem__(self, key):
        h = self.get_hash(key)
        for index, element in enumerate(self.arr[h]):
            if element[0] == key:
                del self.arr[h][index]

    def print(self):
        for h in range(self.MAX):
            print(f'{self.arr[h]}')
            

if __name__ == '__main__':
    handler = open('lipsum.txt', 'r')
    table = HashMap()

    for line in handler:
        line = line.strip()
        line = line.lower()
        words = line.split(" ")
        for word in words:
            if word[-1] in ['.', ','] : word = word[:-1]
            val = 0 if table[word] is None else table[word]
            val += 1
            table[word] = val

    handler.close()
    table.print()
