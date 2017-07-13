#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int StringPriorityComp(char * str1, char * str2) {
	return strlen(str2) - strlen(str1);
}

int main(void) {
	PQueue pq;
	PQueueInit(&pq, StringPriorityComp);

	PEnqueue(&pq, "Good morning");
	PEnqueue(&pq, "I am a boy");
	PEnqueue(&pq, "Priority Queue");
	PEnqueue(&pq, "Do you like coffee");
	PEnqueue(&pq, "I am so happy");

	while (!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}