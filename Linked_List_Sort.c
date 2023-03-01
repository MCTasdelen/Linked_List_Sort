
//Muhammed Cafer Taþdelen 
// CENG 205 DATA STRUCTURES
//ASSIGNMENT 2
//References
//https://youtu.be/pdMPvMM12G0
//https://youtu.be/r3uOBb3BM-0
//https://youtu.be/DGi_gSfYfKo
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
	char name[50];
	char gender;
	struct Student* next;

};
struct Student* insertNode(char* name, char gender, struct Student* list) // linked list creation function
{
	struct Student* s;
	s = malloc(sizeof(struct Student));
	if (s == NULL)
	{
		printf("Memory allocation failed");
		return list;
	}
	strcpy(s->name, name);
	s->gender = gender;
	s->next = list;
	list = s;
	return list;
}
void printList(struct Student* list) //display linked list function
{
	while (list != NULL)
	{
		printf("%s\t%c\n", list->name, list->gender);
		list = list->next;

	}
}
struct Student* sortList(struct Student* list) //sorting of linked list
{

	struct Student* cur = list;
	while (cur->next->next->next->next != NULL) // seperating male and female
	{
		struct Student* prev = cur->next;
		struct Student* p = prev->next;
		if (prev->gender == 'F')
		{
			struct Student* temp = prev;
			cur->next = prev->next;
			temp->next = list;
			list = temp;
		}
		else if (p->gender == 'F')
		{
			struct Student* temp = p;
			prev->next = p->next;
			temp->next = list;
			list = temp;
		}
		cur = cur->next;
	}
	struct Student* middle = list;
	struct Student* var = list;

	while (var->next->next != NULL)//goes to middle of the list
	{
		middle = middle->next;
		var = var->next->next;
	}

	cur = middle;

	while (cur->next != NULL) // Checks the part after the middle of the list
	{
		struct Student* r = cur->next;
		if (r->gender == 'F')
		{
			struct Student* temp = r;
			cur->next = r->next->next;
			temp->next->next = list;
			list = temp;
		}
		cur = cur->next;
	}

	struct Student* r, * p, * q, * end, * temp;
	for (end = NULL; end != list->next; end = p) //alphabetical order of female names
	{
		for (r = p = list; p->next != end; r = p, p = p->next)
		{
			q = p->next;
			if (strcmp(p->name, q->name) > 0 && p->gender == 'F' && q->gender == 'F')
			{
				//using bubble sort 

				p->next = q->next;
				q->next = p;
				if (p != list)
				{
					r->next = q;
				}
				else {
					list = q;
					temp = p;
					p = q;
					q = temp;
				}
			}
		}
	}

	struct Student* r, * p, * q, * end, * temp;
	for (end = NULL; end != list->next; end = p) // reverse alphabetical order of male names
	{
		for (r = p = list; p->next != end; r = p, p = p->next)
		{
			q = p->next;
			if (strcmp(p->name, q->name) < 0 && p->gender == 'M' && q->gender == 'M')
			{
				//using bubble sort 

				p->next = q->next;
				q->next = p;
				if (p != list)
				{
					r->next = q;
				}
				else {
					list = q;
					temp = p;
					p = q;
					q = temp;
				}
			}
		}
	}




	return list;
}
int main()
{
	struct Student* head = NULL;
	head = insertNode("Cenk", 'M', head);
	head = insertNode("Ceyda", 'F', head);
	head = insertNode("Esra", 'F', head);
	head = insertNode("Okan", 'M', head);
	head = insertNode("Tugce", 'F', head);
	head = insertNode("Mehmet", 'M', head);
	head = insertNode("Ayse", 'F', head);
	head = insertNode("Merve", 'F', head);
	head = insertNode("Sedat", 'M', head);
	head = insertNode("Ahmet", 'M', head);

	printList(head);
	head = sortList(head);
	printf("\n\n**********************************\n\n");
	printList(head);


}





