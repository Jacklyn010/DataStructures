import java.util.ArrayList;

class EmptyQueueException extends IndexOutOfBoundsException {
	public EmptyQueueException() {
		super("Queue is empty.");
	}
}

class Queue<T> {
	private ArrayList<T> list;
	
	public Queue() {
		this.list = new ArrayList<T>();
	}
	
	public void enqueue(T item) {
		this.list.add(item);
	}
	
	public T dequeue() {
		if (this.size() == 0) {
			throw new EmptyQueueException();
		}
		
		return this.list.remove(0);
	}
	
	public T peek() {
		if (this.size() == 0) {
			throw new EmptyQueueException();
		}
		
		return this.list.get(0);
	}
	
	public boolean isEmpty() {
		return this.size() == 0;
	}
	
	public int size() {
		return this.list.size();
	}
}
