# [Prim's Algorithm Implementation](prim_algorithm.c)

## Overview
This repository contains an implementation of Prim's algorithm, a widely-used greedy algorithm for finding the Minimum Spanning Tree (MST) in a graph. Prim's algorithm is particularly useful for finding efficient network designs, such as in computer networks or transportation systems.

## Algorithm Complexity
- **Time Complexity**: The time complexity of Prim's algorithm is O(V^2) with an adjacency matrix or O(E + V log V) with an efficient data structure like a binary heap, where V is the number of vertices and E is the number of edges. This implementation uses an adjacency list and a binary heap for optimized performance.

- **Space Complexity**: The space complexity is O(V + E) as it requires storage for the graph representation.

## Files
- **[prim_algorithm.c](prim_algorithm.c)**: This is the main implementation of the Prim's algorithm. It includes the code for MST generation.

- **[./prim/graph.h](./prim/graph.h)**: This header file contains the data structures and functions for graph representation. It is used to construct the graph.

- **[./prim/prim.h](./prim/prim.h)**: The header file `prim.h` holds the core logic of the Prim's algorithm, including the MST construction and relevant data structures.

- **[adj_a.txt](adj_a.txt)**: This text file contains the adjacency list, which represents the graph on which Prim's algorithm operates. You can replace this file with your own graph data or use it as a reference.

## Usage
To use this implementation, follow these steps:
1. Compile the code in `prim_algorithm.c` and link it with the other source files.
2. Prepare your graph data in the format specified in `adj_a.txt` or adapt the code to read your custom data format.
3. Execute the compiled program to find the Minimum Spanning Tree of your graph.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments
Thank you for checking out this implementation of Prim's algorithm. If you find it helpful or have any suggestions for improvements, feel free to contribute or provide feedback.
