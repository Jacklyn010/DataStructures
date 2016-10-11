import java.util.ArrayList;

class EmptyStackException extends IndexOutOfBoundsException {
	public EmptyStackException() {
		super("Stack is empty.");
	}
}

class Stack<T> {
	private ArrayList<T> list;
	
	public Stack() {
		this.list = new ArrayList<T>();
	}
	
	public void push(T item) {
		this.list.add(item);
	}
	
	public T pop() {
		if (this.size() == 0) {
			throw new EmptyStackException();
		}
		
		return this.list.remove(this.size() - 1);
	}
	
	public T peek() {
		if (this.size() == 0) {
			throw new EmptyStackException();
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
