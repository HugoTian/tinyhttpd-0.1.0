1. First start the server. It prints out the port number

   % server

2. Run the client:

   % client <server-hostname> <server-portnum>


3. The client will send a message to the server, that the server will print.
   The client exits. The server continues to wait for further clients.

4. You can repeat step 2. any number of times. Essentially, one server can
   receive requests from multiple clients.


Note that in this case, the server is single-threaded. So, it will handle
client requests sequentially.


Note:

This code does have problems. Identify them.


