/* test2.c */
#include <stdio.h>
#include <string.h>

#define SENTENCE_MAX_LEN 4096


int main(void) {

	char sentence[SENTENCE_MAX_LEN + 1];
	FILE *fd;
	char *path="../../ff-test_bookmarks.html";

	fd = fopen(path, "r");


	int cnt = 0;
	while(cnt <= 25) {
		fgets(sentence, SENTENCE_MAX_LEN, fd);
		printf("%s\n", sentence);
		printf("sentence-%d length: %ld\n", cnt + 1, strlen(sentence));
		printf("\n");
		cnt++;
		memset(sentence, 0, SENTENCE_MAX_LEN + 1);
	}

	printf("=== end ===\n");
	printf("\n");

	return 0;
}

