/* test1.c */
#include <stdio.h>
#include <string.h>


int main(void) {

	char sentence[4096] ="         <DT><A HREF=\"https://support.mozilla.org/products/firefox\" ADD_DATE=\"1649540612\" LAST_MODIFIED=\"1735977942\" ICON_URI=\"fake-favicon-uri:https://support.mozilla.org/products/firefox\" ICON=\"data:image/png;base64,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\">Get Help</A>";

	size_t i = 0;
	while (sentence[i] != '\0') {

		if (sentence[i - 1] == 'A' && sentence[i] == '>') {
			break;
		}

		printf("%ld: %c\n", i + 1, sentence[i]);
		i++;
	}

	printf("sentence length: %ld\n", strlen(sentence));
	printf("\n");

	return 0;
}

