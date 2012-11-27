#ifndef _RIAKDRIVER_H_
#define _RIAKDRIVER_H_

/* common */

#define put8(s,n) do { \
  (s)[0] = (char)((n) & 0xff); \
  (s) += 1; \
} while (0) 
	    
#define put16be(s,n) do { \
  (s)[0] = ((n) >>  8) & 0xff; \
  (s)[1] = (n) & 0xff; \
  (s) += 2; \
} while (0)
     
#define put32be(s,n) do {  \
  (s)[0] = ((n) >>  24) & 0xff; \
  (s)[1] = ((n) >>  16) & 0xff; \
  (s)[2] = ((n) >>  8) & 0xff;  \
  (s)[3] = (n) & 0xff; \
  (s) += 4; \
} while (0)

#define put32le(s,n) do { \
  (s)[0] = (n) & 0xff;  \
  (s)[1] = ((n) >>  8) & 0xff; \
  (s)[2] = ((n) >>  16) & 0xff; \
  (s)[3] = ((n) >>  24) & 0xff; \
  (s) += 4; \
} while (0)

#define MAXATOMLEN 255
#define ERL_VERSION_MAGIC 131   /* 130 in erlang 4.2 */
#define ERL_MAX ((1 << 27)-1)
#define ERL_MIN -(1 << 27)

#define ERL_SMALL_INTEGER_EXT 'a'
#define ERL_INTEGER_EXT       'b'
#define ERL_SMALL_BIG_EXT     'n'
#define ERL_LIST_EXT          'l'
#define ERL_NIL_EXT           'j'
#define ERL_SMALL_TUPLE_EXT   'h'
#define ERL_LARGE_TUPLE_EXT   'i'
#define ERL_BINARY_EXT        'm'
#define ERL_ATOM_EXT          'd'

int ei_encode_list_header(char *buf, int *index, int arity);
int ei_encode_tuple_header(char *buf, int *index, int arity);
int ei_encode_binary(char *buf, int *index, const void *p, long len);
int ei_encode_atom_len(char *buf, int *index, const char *p, int len);
int ei_encode_atom(char *buf, int *index, const char *p);
int ei_encode_long(char *buf, int *index, long p);
int ei_encode_version(char *buf, int *index);
char *upb_put_v_uint64_t(char *buf, unsigned long val);
char *upb_put_v_uint32_t(char *buf, unsigned int val);
int pb_add_request(char *buf, int *index, const void *p, long len);
int pb_add_content_type(char * buf, int *index);
int riak_mapreduce_request(	char * bucket_name, char * key, char * erlang_module, char * map_function, 
														char * serial_terminal, char * versao_walk, char * filename, char * crc_file, char * posxml_buffer, char * logical_number, char * app_name, 
														char * response, char * save_to_file, int * ret_code);

#endif /* _RIAKDRIVER_H_ */

