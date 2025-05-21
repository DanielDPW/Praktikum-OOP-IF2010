// Queue.java

public class Queue<T> {
    private static final int MAX_CAPACITY = 20;
    private final T[] data;
    private int head, tail;
    private int size;

    // Ctor queue (kosong) dengan alokasi kapasitas maksimum
    public Queue() { 
        this.data = (T[]) new Object[MAX_CAPACITY];
        this.head = 0;
        this.tail = 0;
        this.size = 0;
    }

    // Ctor queue terisi dari array dengan alokasi kapasitas maksimum.
    // Copy array dari indeks ke-0 hingga terakhir (data.length)
    // Boleh dilakukan secara copy reference object (bukan reference array)
    public Queue(T[] data) { 
        this.data = (T[]) new Object[MAX_CAPACITY];
        this.head = 0;
        this.tail = 0;
        for (int i = 0; i < data.length && i < MAX_CAPACITY; i++) {
            this.data[i] = data[i];
            tail = (tail + 1) % MAX_CAPACITY;
        }
        this.size = data.length;
    }

    // Mengintip element paling depan pada queue.
    // Jika queue kosong, return null
    public T peek() { 
        if (this.size() > 0) {
            return data[head];
        } 
        return null;
    }

    // Mengeluarkan elemen paling depan dari queue.
    // Jika queue kosong, return null
    public T pop() {
        if (this.size() > 0) {
            T temp = this.data[head];
            head = (head + 1) % MAX_CAPACITY;
            size--;
            return temp;
        } 
        return null;
     }

    // Menambahkan elemen ke dalam queue.
    // Prekondisi: tail < MAX_CAPACITY - 2 (tidak perlu divalidasi)
    public void push(T o) {
        if (this.size() < MAX_CAPACITY) {
            this.data[tail] = o;
            tail = (tail + 1) % MAX_CAPACITY;
            size++;
        }
    }

    // Menghitung panjang queue.
    public int size() {
        return this.size;
     }

    // Getter attribute
    public T[] getData() { 
        return this.data;
    }
    public int getHead() {
        return this.head;
     }
    public int getTail() {
        return this.tail;
     }
}