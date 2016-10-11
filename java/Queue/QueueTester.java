class QueueTester {
	public static void main(String[] args) {
		Queue<Integer> queue = new Queue<Integer>();
		
		for (int i = 5; i >= 0; i--) {
			queue.enqueue(i);
			System.out.println("Enqueued " + i);
		}
		
		System.out.println("Size: " + queue.size());
		System.out.println("Top: " + queue.peek());
		
		while (queue.size() > 0) {
			System.out.println(queue.dequeue());
		}
		
		System.out.println("Size: " + queue.size());
		System.out.print("Top: ");
		
		try {
			System.out.println(queue.peek());
		} catch (EmptyQueueException e) {
			System.out.println(e.toString());
		}
		
		try {
			System.out.println(queue.dequeue());
		} catch (EmptyQueueException e) {
			System.out.println(e.toString());
		}
	}
}
