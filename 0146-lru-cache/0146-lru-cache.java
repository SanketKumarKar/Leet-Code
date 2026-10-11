import java.util.*;

class LRUCache {
    class Node {
        int key, value;
        Node prev, next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    private final int capacity;
    private final HashMap<Integer, Node> map;
    private final Node head, tail;

    public LRUCache(int cap) {
        capacity = cap;
        map = new HashMap<>();

        // Dummy node for help
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head.next = tail;
        tail.prev = head;
    }

    // Remove 
    private void remove(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    // Insert at end kyuki MRU 
    private void insertAtEnd(Node node) {
        Node last = tail.prev;

        last.next = node;
        node.prev = last;

        node.next = tail;
        tail.prev = node;
    }

    // GET: get, remove, insert at mru
    public int get(int key) {
        if (!map.containsKey(key)) {
            return -1;
        }

        Node node = map.get(key);

        remove(node);
        insertAtEnd(node);

        return node.value;
    }

    // PUT: Insert or update a key-value pair
    public void put(int key, int value) {
        // If key already exists, update its value
        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.value = value;

            // MRU
            remove(node);
            insertAtEnd(node);
            return;
        }

        // If cache is full, remove the least recently used node
        if (map.size() == capacity) {
            Node lru = head.next;

            remove(lru);
            map.remove(lru.key);
        }

        // Insert the new key-value
        Node node = new Node(key, value);

        map.put(key, node);
        insertAtEnd(node);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */