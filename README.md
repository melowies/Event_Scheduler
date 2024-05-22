# Priority Queue Implementation in C

This repository contains a C implementation of a priority queue using a heap data structure. The priority queue allows you to add events with associated priorities and times, remove the next event with the highest priority, and print all events in descending order of priority.

## Features

- **Add Event**: Add an event with a given name, time, and priority to the priority queue.
- **Remove Next Event**: Remove the event with the highest priority from the queue.
- **Print All Events**: Print all events in the queue in descending order of priority.
- **Dynamic Capacity**: The priority queue dynamically adjusts its capacity based on the number of events added.

## Usage

1. **Compile**: Compile the source code using a C compiler such as GCC.
    ```bash
    gcc -o priority_queue priority_queue.c
    ```

2. **Run**: Execute the compiled program.
    ```bash
    ./priority_queue
    ```

3. **Menu**: Follow the on-screen menu to perform operations such as adding events, removing events, or printing all events.

## Example

```plaintext
Enter the capacity of the priority queue: 5
Priority Queue Menu:
1. Add event
2. Remove next event
3. Print all events
4. Exit
Enter your choice: 1
Enter event name: Meeting
Enter event time: 15
Enter event priority: 2

Priority Queue Menu:
1. Add event
2. Remove next event
3. Print all events
4. Exit
Enter your choice: 3
Event: Meeting, Time: 15, Priority: 2

Priority Queue Menu:
1. Add event
2. Remove next event
3. Print all events
4. Exit
Enter your choice: 2
Removed event: Meeting, Time: 15, Priority: 2

Priority Queue Menu:
1. Add event
2. Remove next event
3. Print all events
4. Exit
Enter your choice: 4
Exiting...
