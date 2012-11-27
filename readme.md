#To Compile
gcc -o riak-driver riak_driver.c

#To Test
./riak-driver ipriak 8087

#Info about riak mapreduce protocol
http://docs.basho.com/riak/1.2.0/references/apis/protocol-buffers/PBC-MapReduce

#About
A little driver to connect to riak via protocol buffers port and exec a mapreduce job. This driver uses protocol buffers and erlang binary terms.