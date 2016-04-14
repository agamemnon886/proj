#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <parser.h>

int parse_rpc(void) {
	/* Indicator of pass-criteria */
	int count = 0;
	/* Pointer to current line */
	char *line = NULL;
	/* Size of string pointed to by the line */
	size_t size = 0;
	/* Number of line */
	int line_number = 0;
	/* Character to hold '>' symbol */
	char c = 0;

	/* Get next line from the standart input */
	while (getline(&line, &size, stdin) != -1) {
		/* Parse first line */
		if (line_number == 1) {
			/* Make sure that it is RPC request or reply element*/
			if ((strncmp(line, RPC_REQUEST, strlen(RPC_REQUEST)) == 0) ||
				(strncmp(line, RPC_REPLY, strlen(RPC_REPLY)) == 0)) {
				count++;
			} else {
				fprintf(stderr, RPC_ERROR_MSG1);
				return EXIT_FAILURE;
			}

			/* Make sure that the <rpc> element has mandatory attribute
			 * "message-id" as described in RFC 4741.
			 */
			sscanf(line, "%*s message-id=\"%*d\"%*[^>]%c", &c);

			/* Make sure that the '>' symbol exists at the end of <rpc> element.
			 */
			if (c == '>') {
				count++;
			} else {
				fprintf(stderr, RPC_ERROR_MSG2);
				return EXIT_FAILURE;
			}
		}

		/* Increment number of line */
		line_number++;

		/* Make sure that </rpc> exists */
		if (strncmp(line, RPC_END, strlen(RPC_END)) == 0) {
			count++;
		}

		/* Make sure that "]]>]]>" exists as described in RFC 4742 */
		if (strncmp(line, END_SEQ, strlen(END_SEQ)) == 0) {
			/* If it is correct <rpc> element, print "Done" */
			if ((count == 3)) {
				printf("Done\n");
				break;
			} else {
				fprintf(stderr, RPC_ERROR_MSG2);
				return EXIT_FAILURE;
			}
		}
	}

	/* Free memory allocated by getline() */
	if (line != NULL) {
		free(line);
	}

	return EXIT_SUCCESS;
}

