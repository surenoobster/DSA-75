priority_queue<int> maxHeap;
maxHeap.push(2);
maxHeap.push(7);
maxHeap.push(4);
maxHeap.push(1);

cout << maxHeap.top();  // Output: 7 (Largest element)
maxHeap.pop();
cout << maxHeap.top();  // Output: 4 (Next largest element)
