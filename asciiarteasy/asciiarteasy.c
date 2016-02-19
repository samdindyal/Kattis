#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve();

int main(void) {
	solve();
}

void solve() {
	size_t ws, hs, wt, ht;
	int counter;
	char *x;
	if (!scanf("%ld %ld %ld %ld\n", &ws, &hs, &wt, &ht))
		exit(1);

	char **s, **t;
	s = (char**)malloc(hs*sizeof(char*));
	t = (char**)malloc(ht*sizeof(char*));


	for (int i = 0; i < hs; i++)
	{
		s[i] = (char*)malloc(ws*sizeof(char));
		if (!getline((&s[i]), &ws, stdin))
			exit(1);
		s[i][strlen(s[i])-1] = '\0';
	}

	for (int i = 0; i < ht; i++)
	{
		t[i] = (char*)malloc(wt*sizeof(char));
		if (!getline((&t[i]), &wt, stdin))
			exit(1);
		t[i][strlen(t[i])-1] = '\0';
	}

	for (int i = 0; i < hs; i++)
	{
		x = strstr(s[i], t[counter]);
		if (!x)
			counter = 0;
		else if (counter < ht -1)
			counter = (counter + 1) % ht;
		else
		{
			printf("%ld %d\n", x - s[i], i - counter);
			return;
		}
	}

	printf("no match\n");
}