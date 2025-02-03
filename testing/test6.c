#include <stdio.h>
#include <string.h>

#define SENTENCE_MAX_LEN 100000
#define ROWS 220


int main(void) {

	char sentence[SENTENCE_MAX_LEN];
	char reduced[SENTENCE_MAX_LEN];
	FILE *fd;
	char *path="../../ff-test_bookmarks.html";
	fd = fopen(path, "r");


	int cnt = 0;
	while(!feof(fd)) {
		// if (cnt > ROWS) break;
		memset(reduced, 0, SENTENCE_MAX_LEN);
		memset(sentence, 0, SENTENCE_MAX_LEN);
		fgets(sentence, SENTENCE_MAX_LEN, fd);
		int r_pos = 0;
		int s_pos = 0;
		while(sentence[s_pos] != '\0') {
			if (sentence[s_pos] == '"') {
				reduced[r_pos] = sentence[s_pos];
				r_pos++;
				s_pos++;
				break;
			}
			reduced[r_pos] = sentence[s_pos];
			r_pos++;
			s_pos++;
		}

		while(sentence[s_pos] != '\0') {
			if (sentence[s_pos] == '"') {
				reduced[r_pos] = sentence[s_pos];
				r_pos++;
				s_pos++;
				break;
			}
			reduced[r_pos] = sentence[s_pos];
			r_pos++;
			s_pos++;
		}

		while(sentence[s_pos] != '\0') {
			if (sentence[s_pos] == '"' && sentence[s_pos+1] == '>') {
				reduced[r_pos] = sentence[s_pos+1];
				s_pos++;
				break;
			} else {
				s_pos++;
			}
		}
		
		
		while(sentence[s_pos] != '\0') {
			reduced[r_pos] = sentence[s_pos];
			r_pos++;
			s_pos++;
		}

		printf("%s", reduced);
		// printf("%s\n", sentence);
		cnt++;
	}

	fclose(fd);

	printf("\n");

	return 0;
}

