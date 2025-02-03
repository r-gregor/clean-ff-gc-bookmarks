#include <stdio.h>
#include <string.h>

#define SENTENCE_MAX_LEN 4096


int main(void) {

	char sentence[SENTENCE_MAX_LEN + 1];
	char reduced[SENTENCE_MAX_LEN + 1];
	FILE *fd;
	char *path="../../ff-test_bookmarks.html";

	fd = fopen(path, "r");


	int cnt = 0;
	while(cnt <= 25) {
		fgets(sentence, SENTENCE_MAX_LEN, fd);
		int j = 0;
		while(sentence[j] != '\0') {
			reduced[j] = sentence[j];
			if(sentence[j] == '"') break;
			j++;
		}
		printf("%s\n", reduced);
		memset(sentence, 0, SENTENCE_MAX_LEN + 1);
		memset(reduced, 0, SENTENCE_MAX_LEN + 1);
		cnt++;
	}

	printf("=== end ===\n");
	printf("\n");

	return 0;
}

