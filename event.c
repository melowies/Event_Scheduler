#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int time;
    int priority;
} event;

typedef struct {
    event *events;
    int size;
    int capacity;
} p_queue; // priority queue

void swap(event *a, event *b) {
    event temp = *a;
    *a = *b;
    *b = temp;
}

p_queue *create_p_queue(int capacity) {
    p_queue *pq = (p_queue *)malloc(sizeof(p_queue));
    pq->events = (event *)malloc(capacity * sizeof(event));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void heap_up(p_queue *pq, int index) {
    while (index != 0 && pq->events[(index - 1) / 2].priority < pq->events[index].priority) {
        swap(&pq->events[(index - 1) / 2], &pq->events[index]);
        index = (index - 1) / 2;
    }
}

void heap_down(p_queue *pq, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->events[left].priority > pq->events[largest].priority) {
        largest = left;
    }

    if (right < pq->size && pq->events[right].priority > pq->events[largest].priority) {
        largest = right;
    }

    if (largest != index) {
        swap(&pq->events[index], &pq->events[largest]);
        heap_down(pq, largest);
    }
}

void insert_event(p_queue *pq, event e) {
    if (pq->size == pq->capacity) {
        printf("Queue is full!\n");
        return;
    }
    pq->events[pq->size] = e;
    heap_up(pq, pq->size);
    pq->size++;
}

event extract_max(p_queue *pq) {
    if (pq->size == 0) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    event root = pq->events[0];
    pq->events[0] = pq->events[pq->size - 1];
    pq->size--;
    heap_down(pq, 0);
    return root;
}

void add_event(p_queue *pq, char *name, int time, int priority) {
    event e;
    strcpy(e.name, name);
    e.time = time;
    e.priority = priority;
    insert_event(pq, e);
}

event remove_next_event(p_queue *pq) {
    return extract_max(pq);
}

void print_events(p_queue *pq) {
    int original_size = pq->size;
    event *events = (event *)malloc(pq->size * sizeof(event));
    for (int i = 0; i < original_size; i++) {
        events[i] = extract_max(pq);
    }
    for (int i = original_size - 1; i >= 0; i--) {
        printf("Event: %s, Time: %d, Priority: %d\n", events[i].name, events[i].time, events[i].priority);
    }
    for (int i = 0; i < original_size; i++) {
        insert_event(pq, events[i]);
    }
    free(events);
}

void display_menu() {
    printf("\nPriority Queue Menu:\n");
    printf("1. Add event\n");
    printf("2. Remove next event\n");
    printf("3. Print all events\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int capacity;
    printf("Enter the capacity of the priority queue: ");
    scanf("%d", &capacity);

    p_queue *pq = create_p_queue(capacity);
    int choice;
    char name[50];
    int time, priority;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter event name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter event time: ");
                scanf("%d", &time);
                printf("Enter event priority: ");
                scanf("%d", &priority);
                add_event(pq, name, time, priority);
                break;
            case 2:
                if (pq->size > 0) {
                    event e = remove_next_event(pq);
                    printf("Removed event: %s, Time: %d, Priority: %d\n", e.name, e.time, e.priority);
                } else {
                    printf("The queue is empty.\n");
                }
                break;
            case 3:
                if (pq->size > 0) {
                    print_events(pq);
                } else {
                    printf("The queue is empty.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                free(pq->events);
                free(pq);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    free(pq->events);
    free(pq);   
    return 0;
}