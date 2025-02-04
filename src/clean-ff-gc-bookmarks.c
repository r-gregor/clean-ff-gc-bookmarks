/* src/clean-ff-gc-bookmarks.c */
/* from: testing/test9.c */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SENTENCE_MAX_LEN 100000

bool is_substring(char *substr, char *string);

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

		if(is_substring("search", sentence) || is_substring("imgres", sentence)) {
			continue;
		}

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


/* from: https://github.com/portfoliocourses/c-example-code/blob/main/substr_substring.c
 *       Check If A String Is A Substring Of Another String | C Programming Example
 *       https://www.youtube.com/watch?v=tx37dJZTfMM
 *
 * returns true if 'substr' is a substring of strign, and false otherwise
 */
bool is_substring(char *substr, char *string) {
	int slen = strlen(string);
	int clen = strlen(substr);
	int end = slen - clen + 1;

	for (int i = 0; i < end; i++) {
		bool substr_found = true;

		for (int j = 0; j < clen; j++) {
			if (substr[j] != string[i + j]) {
				substr_found = false;
				break;
			}
		}
		
		if (substr_found) return true;
	}

	return false;
}

