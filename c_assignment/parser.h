#if !defined(parser_h)

/* Macro definitions */
#define END_SEQ "]]>]]>"
#define RPC_REQUEST "<rpc message-id="
#define RPC_REPLY "<rpc-reply message-id="
#define RPC_END "</rpc>"
#define RPC_ERROR_MSG1 "It is not <rpc> element\n"
#define RPC_ERROR_MSG2 "Invalid <rpc> element\n"

/* Function declarations */
extern int parse_rpc(void);

#endif /* parser_h */

