#include <stdlib.h>
#include <parser.h>

int main()
{
	int ret = -1;

	/* Call parse_rpc() to parse <rpc> element from standart input */
	ret = parse_rpc();
	if (ret != 0)
		return EXIT_FAILURE;
	else
		return EXIT_SUCCESS;
}

