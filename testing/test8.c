/* test8.c */
#include <stdio.h>
#include <string.h>

#define SENTENCE_MAX_LEN 100000

int main(int argc, char **argv) {
	
	char *path;

	if (argc == 2) {
		path = argv[1];
	} else {
		path="../../ff-test_bookmarks.html";
	}

	char sentence[SENTENCE_MAX_LEN];
	char reduced[SENTENCE_MAX_LEN];
	FILE *fd;
	if ((fd = fopen(path, "r")) == NULL) {
		perror("[ERROR] could NOT open file");
		return -1;
	}


	while (fgets(sentence, SENTENCE_MAX_LEN, fd) != NULL) {
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
		memset(reduced, 0, SENTENCE_MAX_LEN);
		memset(sentence, 0, SENTENCE_MAX_LEN);
	}

	fclose(fd);

	printf("\n");

	return 0;
}

