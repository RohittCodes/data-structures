## Graph traversal

    Use a queue -> Just the same stuff as traversing a binary tree

    Steps:
    1. You could basically start with any node you want to push into the queue to traverse it. Initialize a queue before performing operations.
    2. For e.g., let the graph be,
    0 - 1
    |
    2
    |
    4 - 3
        a. We start with the node 0
        b. Check if 0 has been traversed earlier or not. Use an array of boolean type to check if the node has been visited or not. Populate it up with false values. Now you could Mark true if the node has been visited. So now, the first index is true.
        c. If visited earlier mark it true or else


    We could even use a stack for traversal
