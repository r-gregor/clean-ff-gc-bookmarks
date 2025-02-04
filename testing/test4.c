/* test4.c */
#include <stdio.h>
#include <string.h>

#define SENTENCE_MAX_LEN 4096
#define ROWS 50


int main(void) {

	char sentence[SENTENCE_MAX_LEN];
	char reduced[SENTENCE_MAX_LEN];
	FILE *fd;
	char *path="../../ff-test_bookmarks.html";

	fd = fopen(path, "r");


	int cnt = 0;
	while(cnt <= ROWS) {
		memset(sentence, 0, SENTENCE_MAX_LEN);
		memset(reduced, 0, SENTENCE_MAX_LEN);
		fgets(sentence, SENTENCE_MAX_LEN, fd);
		int s_pos = 0;
		int r_pos = 0;

		while(sentence[s_pos] != '\0') {
			reduced[r_pos] = sentence[s_pos];
			if(sentence[s_pos] == '"') {
				s_pos++;
				r_pos++;
				break;
			}
			s_pos++;
			r_pos++;
		}

		while(sentence[s_pos] != '\0') {
			reduced[r_pos] = sentence[s_pos];
			if(sentence[s_pos] == '"') {
				s_pos++;
				r_pos++;
				break;
			}
			s_pos++;
			r_pos++;
		}

		while(sentence[s_pos] != '>') {
			s_pos++;
		}

		while(sentence[s_pos] != '\0') {
			reduced[r_pos] = sentence[s_pos];
			s_pos++;
			r_pos++;
		}
		reduced[r_pos-1] = '\n';

		printf("%s", reduced);
		cnt++;
	}

	printf("=== end ===\n");
	printf("\n");

	return 0;
}

